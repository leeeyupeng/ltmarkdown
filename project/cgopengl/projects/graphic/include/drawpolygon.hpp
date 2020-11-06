#ifndef _drawpolygon_H
#define _drawpolygon_H
namespace lt {
	template<class T>
	struct Vector2;
	template<class T>
	struct Vector3;
	class drawpolygon
	{
	private:
		unsigned int VAO, VBO;
		unsigned int count;
		unsigned int size;
		lt::Vector2<int>* verticle;
		lt::Vector3<float>* color;
	public:
		drawpolygon(int _size, lt::Vector2<int>* _verticle, lt::Vector3<float>* _color);
		~drawpolygon();
		void Init();
		void Display();
		void Destroy();
	};
}
#endif