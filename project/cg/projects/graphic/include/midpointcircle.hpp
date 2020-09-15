#ifndef _midpointcircle_H
#define _midpointcircle_H
namespace lt {
	template<class T>
	struct Vector2;
	template<class T>
	struct Vector3;
	class midpointcircle
	{
	private:
		unsigned int VAO,VBO;
		unsigned int count;

		lt::Vector2<int> center;
		int radiu;
		lt::Vector3 <float>* v;
	public:
		midpointcircle(lt::Vector2<int> _center,int _radiu);
		~midpointcircle();
		void circlepoint(int  x, int y);
		void Init();
		void Display();
		void Destroy();
	};
}
#endif