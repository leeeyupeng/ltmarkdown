#ifndef _drawpoint_H
#define _drawpoint_H
namespace lt {
	template<class T>
	struct Vector2;
	template<class T>
	struct Vector3;
	class drawpoint
	{
	private:
		unsigned int VAO, VBO;

		lt::Vector2<float> a;
		lt::Vector3<float> aColor;
	public:
		drawpoint(lt::Vector2<float> _a, lt::Vector3<float> _aColor);
		~drawpoint();
		void Init();
		void Display();
		void Destroy();
	};
}
#endif