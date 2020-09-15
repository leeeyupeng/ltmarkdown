#include <iostream>
#include <opencv2/opencv.hpp>

#include "global.hpp"
#include "rasterizer.hpp"
#include "Triangle.hpp"
#include "Shader.hpp"
#include "Texture.hpp"
#include "OBJ_Loader.h"

Eigen::Matrix4f get_view_matrix(Eigen::Vector3f eye_pos)
{
    Eigen::Matrix4f view = Eigen::Matrix4f::Identity();

    Eigen::Matrix4f translate;
    translate << 1,0,0,-eye_pos[0],
                 0,1,0,-eye_pos[1],
                 0,0,1,-eye_pos[2],
                 0,0,0,1;

    view = translate*view;

    return view;
}

Eigen::Matrix4f get_model_matrix(Eigen::Vector3f rot_pos,Eigen::Vector3f axis,float angle)
{
    Eigen::Matrix4f rotation_translate;
    rotation_translate << 1, 0, 0, -rot_pos.x(),
            0, 1, 0, -rot_pos.y(),
            0, 0, 1, -rot_pos.z(),
            0, 0, 0, 1;

    axis.normalize();

    Eigen::Vector3f axisx = Eigen::Vector3f(0,axis.y(),axis.z());
    axisx.normalize();
    if(axis.y() == 0.0f && axis.z() == 0.0f){axisx.z() = 1.0f;}
    Eigen::Matrix4f rotationx= Eigen::Matrix4f::Identity();
    rotationx<<1,0,0,0,
                0,axisx.dot(Eigen::Vector3f(0.0f,0.0f,1.0f)),-axisx.dot(Eigen::Vector3f(0.0f,1.0f,0.0f)),0,
                0,axisx.dot(Eigen::Vector3f(0.0f,1.0f,0.0f)),axisx.dot(Eigen::Vector3f(0.0f,0.0f,1.0f)),0,
                0,0,0,1;

    Eigen::Vector4f axisy4 = rotationx * Eigen::Vector4f(axis.x(),axis.y(),axis.z(),0.0f);
    Eigen::Vector3f axisy = Eigen::Vector3f(axisy4.x(),axisy4.y(),axisy4.z());
    axisy.normalize();
    Eigen::Matrix4f rotationy= Eigen::Matrix4f::Identity();
    rotationy<<
                axisy.dot(Eigen::Vector3f(0.0f,0.0f,1.0f)),0,-axisy.dot(Eigen::Vector3f(1.0f,0.0f,0.0f)),0,
                0,1,0,0,
                axisy.dot(Eigen::Vector3f(1.0f,0.0f,0.0f)),0,axisy.dot(Eigen::Vector3f(0.0f,0.0f,1.0f)),0,
                0,0,0,1;
    Eigen::Matrix4f rotationz = Eigen::Matrix4f::Identity();
    angle = angle * MY_PI / 180.f;
    rotationz << cos(angle),-sin(angle),0 ,0,
                sin(angle), cos(angle),0, 0,
                0, 0, 1, 0,
                0, 0, 0, 1;

    std::cout<<"rotation_xyz:"<<rotationx.inverse()*rotationy.inverse() *rotationz * rotationy * rotationx<<std::endl;
    Eigen::Matrix4f rotation = Eigen::Matrix4f::Identity();
    rotation = rotation_translate.inverse() * rotationx.inverse()*rotationy.inverse() *rotationz * rotationy * rotationx * rotation_translate;

    Eigen::Matrix3f rotation_rot;
    rotation_rot = cos(angle) * Eigen::Matrix3f::Identity();
    //std::cout<<"rotation_rot 1:"<<rotation_rot<<std::endl;
    rotation_rot += (1-cos(angle)) * Eigen::Vector3f(axis.x(),axis.y(),axis.z()) * Eigen::Vector3f(axis.x(),axis.y(),axis.z()).transpose();
    //std::cout<<"rotation_rot 2:"<<rotation_rot<<std::endl;
    Eigen::Matrix3f mataxis;
    mataxis<<0,-axis.z(),axis.y(),
            axis.z(),0,-axis.x(),
            -axis.y(),axis.x(),0;
    rotation_rot += sin(angle) * mataxis;
    std::cout<<"rotation_rot:"<<rotation_rot<<std::endl;

    Eigen::Matrix4f rotation_rot4 = Eigen::Matrix4f::Identity();

    float aaa=rotation_rot(0,0);
    //std::cout<<"rotation_rot(0,0):"<<rotation_rot(0,0)<<std::endl;
    //std::cout<<"rotation_rot:"<<rotation_rot<<std::endl;
    rotation_rot4<<rotation_rot(0,0),rotation_rot(0,1),rotation_rot(0,2),0,
                    rotation_rot(1,0),rotation_rot(1,1),rotation_rot(1,2),0,
                    rotation_rot(2,0),rotation_rot(2,1),rotation_rot(2,2),0,
                    0,0,0,1;

    //rotation = rotation_translate.inverse() * rotation_rot4 * rotation_translate;
    //rotation = rotation_rot4;
    Eigen::Matrix4f scale;
    scale << 1, 0, 0, 0,
              0, 1, 0, 0,
              0, 0, 1, 0,
              0, 0, 0, 1;

    Eigen::Matrix4f translate;
    translate << 1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1;

    return translate * rotation * scale;
}

Eigen::Matrix4f get_projection_matrix(float eye_fov, float aspect_ratio, float zNear, float zFar)
{
    // TODO: Use the same projection matrix from the previous assignments
    Eigen::Matrix4f projection;

    float rad = eye_fov / 180.0f * 0.5f* MY_PI;
    float n = -zNear;
    float f = -zFar;
    float t = abs(n) * tan(rad);
    float b = -t;
    float r = t * aspect_ratio;
    float l = -r;

    Eigen::Matrix4f persp = Eigen::Matrix4f::Identity();
    persp<<
    n,   0,  0,  0,
    0,   n,   0,  0,
    0,   0,  n+f,  -n*f,
    0,   0,  1,  0;
    

    Eigen::Matrix4f ortho_translate = Eigen::Matrix4f::Identity();
    Eigen::Matrix4f ortho_scale = Eigen::Matrix4f::Identity();
    Eigen::Matrix4f ortho = Eigen::Matrix4f::Identity();
    ortho_translate<<
    1,  0,  0,   -(r+l)/2.0f,
    0,  1,  0,   -(t+b)/2.0f,
    0,  0,  1,   -(n+f)/2.0f,
    0,  0,  0,   1;
    ortho_scale<<
    2.0f/(r-l),  0,   0,   0,
    0,2.0f/(t-b),   0,   0,
    0,  0,2.0f/(n-f),   0,
    0,  0,   0,   1;
    ortho = ortho_scale * ortho_translate;

    projection = ortho * persp;
    return projection;

}

Eigen::Vector3f vertex_shader(const vertex_shader_payload& payload)
{
    return payload.position;
}

Eigen::Vector3f normal_fragment_shader(const fragment_shader_payload& payload)
{
    Eigen::Vector3f return_color = (payload.normal.head<3>().normalized() + Eigen::Vector3f(1.0f, 1.0f, 1.0f)) / 2.f;
    Eigen::Vector3f result;
    result << return_color.x() * 255, return_color.y() * 255, return_color.z() * 255;
    return result;
}

static Eigen::Vector3f reflect(const Eigen::Vector3f& vec, const Eigen::Vector3f& axis)
{
    auto costheta = vec.dot(axis);
    return (2 * costheta * axis - vec).normalized();
}

struct light
{
    Eigen::Vector3f position;
    Eigen::Vector3f intensity;
};

Eigen::Vector3f texture_fragment_shader(const fragment_shader_payload& payload)
{
    Eigen::Vector3f return_color = {0, 0, 0};
    if (payload.texture)
    {
        // TODO: Get the texture value at the texture coordinates of the current fragment
        return_color = payload.texture->getColor(payload.tex_coords.x(),payload.tex_coords.y());
        //std::cout<<"return_color:"<<return_color<<std::endl;

    }
    Eigen::Vector3f texture_color;
    texture_color << return_color.x(), return_color.y(), return_color.z();

    Eigen::Vector3f ka = Eigen::Vector3f(0.005, 0.005, 0.005);
    Eigen::Vector3f kd = texture_color / 255.f;
    Eigen::Vector3f ks = Eigen::Vector3f(0.7937, 0.7937, 0.7937);

    auto l1 = light{{20, 20, 20}, {500, 500, 500}};
    auto l2 = light{{-20, 20, 0}, {500, 500, 500}};

    std::vector<light> lights = {l1, l2};
    Eigen::Vector3f amb_light_intensity{10, 10, 10};
    Eigen::Vector3f eye_pos{0, 0, 10};

    float p = 150;

    Eigen::Vector3f color = texture_color;
    Eigen::Vector3f point = payload.view_pos;
    Eigen::Vector3f normal = payload.normal;

    Eigen::Vector3f result_color = {0, 0, 0};

    // //result_color = texture_color;
    // for (auto& light : lights)
    // {
    //     // TODO: For each light source in the code, calculate what the *ambient*, *diffuse*, and *specular* 
    //     // components are. Then, accumulate that result on the *result_color* object.

    //     Eigen::Vector3f l = light.position - point;
    //     Eigen::Vector3f v = eye_pos - point;
    //     result_color += Eigen::Vector3f(ka.x() * amb_light_intensity.x(),ka.y() * amb_light_intensity.y(),ka.z() * amb_light_intensity.z());
    //     result_color += Eigen::Vector3f(kd.x() * light.intensity.x(),kd.y() * light.intensity.y(),kd.z() * light.intensity.z())/ (l.x() * l.x() + l.y() * l.y()) * MAX(0,normal.normalized().dot(l.normalized()));
    //     result_color += Eigen::Vector3f(ks.x() * light.intensity.x(),ks.y() * light.intensity.y(),ks.z() * light.intensity.z())/ (l.x() * l.x() + l.y() * l.y()) * pow(MAX(0,normal.normalized().dot((l + v).normalized())),p);
    //     //result_color = ka * amb_light_intensity + kd * light.intensity / (l.x() * l.x() + l.y() * l.y()) * MAX(0,normal.dot(l))
    //     // + ks * light.intensity / (l.x() * l.x() + l.y() * l.y()) * pow(MAX(0,normal.dot((l + v).normalized())),p);

    // }
    // result_color = Eigen::Vector3f(color.x() * result_color.x(),color.y() * result_color.y(),color.z() * result_color.z());
    // //result_color = texture_color * result_color;
    for (auto& light : lights)
    {
        // TODO: For each light source in the code, calculate what the *ambient*, *diffuse*, and *specular* 
        // components are. Then, accumulate that result on the *result_color* object.

        Eigen::Vector3f light_color= {0, 0, 0};
        Eigen::Vector3f l = light.position - point;
        Eigen::Vector3f v = eye_pos - point;
        light_color += Eigen::Vector3f(ka.x() * amb_light_intensity.x(),ka.y() * amb_light_intensity.y(),ka.z() * amb_light_intensity.z());
        light_color += Eigen::Vector3f(kd.x() * light.intensity.x(),kd.y() * light.intensity.y(),kd.z() * light.intensity.z())/ (l.x() * l.x() + l.y() * l.y()) * MAX(0,normal.normalized().dot(l.normalized()));
        light_color += Eigen::Vector3f(ks.x() * light.intensity.x(),ks.y() * light.intensity.y(),ks.z() * light.intensity.z())/ (l.x() * l.x() + l.y() * l.y()) * pow(MAX(0,normal.normalized().dot((l + v).normalized())),p);
        result_color += Eigen::Vector3f(color.x() * light_color.x(),color.y() * light_color.y(),color.z() * light_color.z())  / 255.0f;
    }
    return result_color * 255.f;
}

Eigen::Vector3f phong_fragment_shader(const fragment_shader_payload& payload)
{
    Eigen::Vector3f ka = Eigen::Vector3f(0.005, 0.005, 0.005);
    Eigen::Vector3f kd = payload.color;
    Eigen::Vector3f ks = Eigen::Vector3f(0.7937, 0.7937, 0.7937);

    auto l1 = light{{20, 20, 20}, {500, 500, 500}};
    auto l2 = light{{-20, 20, 0}, {500, 500, 500}};

    std::vector<light> lights = {l1, l2};
    Eigen::Vector3f amb_light_intensity{10, 10, 10};
    Eigen::Vector3f eye_pos{0, 0, 10};

    float p = 150;

    Eigen::Vector3f color = payload.color;
    Eigen::Vector3f point = payload.view_pos;
    Eigen::Vector3f normal = payload.normal;

    Eigen::Vector3f result_color = {0, 0, 0};
    for (auto& light : lights)
    {
        // TODO: For each light source in the code, calculate what the *ambient*, *diffuse*, and *specular* 
        // components are. Then, accumulate that result on the *result_color* object.

        Eigen::Vector3f light_color= {0, 0, 0};
        Eigen::Vector3f l = light.position - point;
        Eigen::Vector3f v = eye_pos - point;
        light_color += Eigen::Vector3f(ka.x() * amb_light_intensity.x(),ka.y() * amb_light_intensity.y(),ka.z() * amb_light_intensity.z());
        light_color += Eigen::Vector3f(kd.x() * light.intensity.x(),kd.y() * light.intensity.y(),kd.z() * light.intensity.z())/ (l.x() * l.x() + l.y() * l.y()) * MAX(0,normal.normalized().dot(l.normalized()));
        light_color += Eigen::Vector3f(ks.x() * light.intensity.x(),ks.y() * light.intensity.y(),ks.z() * light.intensity.z())/ (l.x() * l.x() + l.y() * l.y()) * pow(MAX(0,normal.normalized().dot((l + v).normalized())),p);
        result_color += Eigen::Vector3f(color.x() * light_color.x(),color.y() * light_color.y(),color.z() * light_color.z());
    }

    return result_color * 255.f;
}



Eigen::Vector3f displacement_fragment_shader(const fragment_shader_payload& payload)
{
    
    Eigen::Vector3f ka = Eigen::Vector3f(0.005, 0.005, 0.005);
    Eigen::Vector3f kd = payload.color;
    Eigen::Vector3f ks = Eigen::Vector3f(0.7937, 0.7937, 0.7937);

    auto l1 = light{{20, 20, 20}, {500, 500, 500}};
    auto l2 = light{{-20, 20, 0}, {500, 500, 500}};

    std::vector<light> lights = {l1, l2};
    Eigen::Vector3f amb_light_intensity{10, 10, 10};
    Eigen::Vector3f eye_pos{0, 0, 10};

    float p = 150;

    Eigen::Vector3f color = payload.color; 
    Eigen::Vector3f point = payload.view_pos;
    Eigen::Vector3f normal = payload.normal;

    float kh = 0.2, kn = 0.1;
    
    // TODO: Implement displacement mapping here
    // Let n = normal = (x, y, z)
    // Vector t = (x*y/sqrt(x*x+z*z),sqrt(x*x+z*z),z*y/sqrt(x*x+z*z))
    // Vector b = n cross product t
    // Matrix TBN = [t b n]
    // dU = kh * kn * (h(u+1/w,v)-h(u,v))
    // dV = kh * kn * (h(u,v+1/h)-h(u,v))
    // Vector ln = (-dU, -dV, 1)
    // Position p = p + kn * n * h(u,v)
    // Normal n = normalize(TBN * ln)


    Eigen::Vector3f result_color = {0, 0, 0};

    for (auto& light : lights)
    {
        // TODO: For each light source in the code, calculate what the *ambient*, *diffuse*, and *specular* 
        // components are. Then, accumulate that result on the *result_color* object.

        Eigen::Vector3f light_color= {0, 0, 0};
        Eigen::Vector3f l = light.position - point;
        Eigen::Vector3f v = eye_pos - point;
        light_color += Eigen::Vector3f(ka.x() * amb_light_intensity.x(),ka.y() * amb_light_intensity.y(),ka.z() * amb_light_intensity.z());
        light_color += Eigen::Vector3f(kd.x() * light.intensity.x(),kd.y() * light.intensity.y(),kd.z() * light.intensity.z())/ (l.x() * l.x() + l.y() * l.y()) * MAX(0,normal.normalized().dot(l.normalized()));
        light_color += Eigen::Vector3f(ks.x() * light.intensity.x(),ks.y() * light.intensity.y(),ks.z() * light.intensity.z())/ (l.x() * l.x() + l.y() * l.y()) * pow(MAX(0,normal.normalized().dot((l + v).normalized())),p);
        result_color += Eigen::Vector3f(color.x() * light_color.x(),color.y() * light_color.y(),color.z() * light_color.z());
    }

    return result_color * 255.f;
}


Eigen::Vector3f bump_fragment_shader(const fragment_shader_payload& payload)
{
    
    Eigen::Vector3f ka = Eigen::Vector3f(0.005, 0.005, 0.005);
    Eigen::Vector3f kd = payload.color;
    Eigen::Vector3f ks = Eigen::Vector3f(0.7937, 0.7937, 0.7937);

    auto l1 = light{{20, 20, 20}, {500, 500, 500}};
    auto l2 = light{{-20, 20, 0}, {500, 500, 500}};

    std::vector<light> lights = {l1, l2};
    Eigen::Vector3f amb_light_intensity{10, 10, 10};
    Eigen::Vector3f eye_pos{0, 0, 10};

    float p = 150;

    Eigen::Vector3f color = payload.color; 
    Eigen::Vector3f point = payload.view_pos;
    Eigen::Vector3f normal = payload.normal;


    float kh = 0.2, kn = 0.1;

    // TODO: Implement bump mapping here
    // Let n = normal = (x, y, z)
    // Vector t = (x*y/sqrt(x*x+z*z),sqrt(x*x+z*z),z*y/sqrt(x*x+z*z))
    // Vector b = n cross product t
    // Matrix TBN = [t b n]
    // dU = kh * kn * (h(u+1/w,v)-h(u,v))
    // dV = kh * kn * (h(u,v+1/h)-h(u,v))
    // Vector ln = (-dU, -dV, 1)
    // Normal n = normalize(TBN * ln)


    Eigen::Vector3f result_color = {0, 0, 0};
    result_color = normal;

    return result_color * 255.f;
}

int main(int argc, const char** argv)
{
    std::cout<<"argc:"<<argc<<std::endl;
    std::vector<Triangle*> TriangleList;

    float angle = 0.0f;
    bool command_line = false;

    std::string filename = "output.png";
    objl::Loader Loader;
    std::string obj_path = "../models/spot/";

    // Load .obj File
    bool loadout = Loader.LoadFile("../models/spot/spot_triangulated_good.obj");
    //bool loadout = Loader.LoadFile("../models/Crate/Crate1.obj");
    for(auto mesh:Loader.LoadedMeshes)
    {
        for(int i=0;i<mesh.Vertices.size();i+=3)
        {
            Triangle* t = new Triangle();
            for(int j=0;j<3;j++)
            {
                t->setVertex(j,Vector4f(mesh.Vertices[i+j].Position.X,mesh.Vertices[i+j].Position.Y,mesh.Vertices[i+j].Position.Z,1.0));
                t->setNormal(j,Vector3f(mesh.Vertices[i+j].Normal.X,mesh.Vertices[i+j].Normal.Y,mesh.Vertices[i+j].Normal.Z));
                t->setTexCoord(j,Vector2f(mesh.Vertices[i+j].TextureCoordinate.X, mesh.Vertices[i+j].TextureCoordinate.Y));
            }
            TriangleList.push_back(t);
        }
    }

    rst::rasterizer r(700, 700);

    auto texture_path = "hmap.jpg";
    r.set_texture(Texture(obj_path + texture_path));

    std::function<Eigen::Vector3f(fragment_shader_payload)> active_shader = phong_fragment_shader;

    active_shader = texture_fragment_shader;
    texture_path = "spot_texture.png";
    r.set_texture(Texture(obj_path + texture_path));


    if (argc >= 2)
    {
        command_line = true;
        filename = std::string(argv[1]);

        if (argc == 3 && std::string(argv[2]) == "texture")
        {
            std::cout << "Rasterizing using the texture shader\n";
            active_shader = texture_fragment_shader;
            texture_path = "spot_texture.png";
            r.set_texture(Texture(obj_path + texture_path));
        }
        else if (argc == 3 && std::string(argv[2]) == "normal")
        {
            std::cout << "Rasterizing using the normal shader\n";
            active_shader = normal_fragment_shader;
        }
        else if (argc == 3 && std::string(argv[2]) == "phong")
        {
            std::cout << "Rasterizing using the phong shader\n";
            active_shader = phong_fragment_shader;
        }
        else if (argc == 3 && std::string(argv[2]) == "bump")
        {
            std::cout << "Rasterizing using the bump shader\n";
            active_shader = bump_fragment_shader;
        }
        else if (argc == 3 && std::string(argv[2]) == "displacement")
        {
            std::cout << "Rasterizing using the bump shader\n";
            active_shader = displacement_fragment_shader;
        }
    }

    Eigen::Vector3f eye_pos = {0,0,10};

    r.set_vertex_shader(vertex_shader);
    r.set_fragment_shader(active_shader);

    int key = 0;
    int frame_count = 0;

    if (command_line)
    {
        r.clear(rst::Buffers::Color | rst::Buffers::Depth);
        r.set_model(get_model_matrix(Eigen::Vector3f(-2.0f,-2.0f,0.0f),Eigen::Vector3f(0.0f,1.0f,0.0f),angle));
        r.set_view(get_view_matrix(eye_pos));
        r.set_projection(get_projection_matrix(45.0, 1, 0.1, 50));

        r.draw(TriangleList);
        cv::Mat image(700, 700, CV_32FC3, r.frame_buffer().data());
        image.convertTo(image, CV_8UC3, 1.0f);
        cv::cvtColor(image, image, cv::COLOR_RGB2BGR);

        cv::imwrite(filename, image);

        return 0;
    }

    while(key != 27)
    {
        r.clear(rst::Buffers::Color | rst::Buffers::Depth);

        r.set_model(get_model_matrix(Eigen::Vector3f(-1.0f,-1.0f,0.0f),Eigen::Vector3f(1.0f,1.0f,0.0f),angle));
        r.set_view(get_view_matrix(eye_pos));
        r.set_projection(get_projection_matrix(45.0, 1, 0.1, 50));

        //r.draw(pos_id, ind_id, col_id, rst::Primitive::Triangle);
        r.draw(TriangleList);

        cv::Mat image(700, 700, CV_32FC3, r.frame_buffer().data());
        image.convertTo(image, CV_8UC3, 1.0f);
        cv::cvtColor(image, image, cv::COLOR_RGB2BGR);

        cv::imshow("image", image);
        //cv::imwrite(filename, image);
        key = cv::waitKey(10);

        if (key == 'a' )
        {
            angle -= 10;
        }
        else if (key == 'd')
        {
            angle += 10;
        }
        std::cout<<"angle:"<<angle<<std::endl;

    }
    return 0;
}
