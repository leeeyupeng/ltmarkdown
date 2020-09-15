#ifndef _midpointline_H
#define _midpointline_H
namespace lt {
	template<class T>
	struct Vector2;
	template<class T>
	struct Vector3;
	class midpointline
	{
	private:
		unsigned int VAO,VBO;
		unsigned int count;

		lt::Vector2<int> a,b;
		lt::Vector3<float> aColor, bColor;
	public:
		midpointline(lt::Vector2<int> _a, lt::Vector3<float> _aColor, lt::Vector2<int> _b, lt::Vector3<float> _bColor);
		~midpointline();
		void Init();
		void Display();
		void Destroy();
	};
}
#endif