#ifndef _bresenhamline_H
#define _bresenhamline_H
namespace lt {
	template<class T>
	struct Vector2;
	template<class T>
	struct Vector3;
	class bresenhamline
	{
	private:
		unsigned int VAO,VBO;
		unsigned int count;

		lt::Vector2<int> a,b;
		lt::Vector3<float> aColor, bColor;
	public:
		bresenhamline(lt::Vector2<int> _a, lt::Vector3<float> _aColor, lt::Vector2<int> _b, lt::Vector3<float> _bColor);
		~bresenhamline();
		void Init();
		void Display();
		void Destroy();
	};
}
#endif