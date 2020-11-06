#ifndef _polygonfill_edgemark_H
#define _polygonfill_edgemark_H
namespace lt {
	template<class T>
	struct Vector2;
	template<class T>
	struct Vector3;
	class polygonfill_edgemark
	{
	private:
		unsigned int VAO, VBO;
		unsigned int count;
		unsigned int size;
		lt::Vector2<int>* verticle;
		lt::Vector3<float>* color;
	public:
		polygonfill_edgemark(int size, lt::Vector2<int>* _verticle, lt::Vector3<float>* _color);
		~polygonfill_edgemark();
		void Init();
		void Display();
		void Destroy();
	};
}
#endif