#ifndef _ddaline_H
#define _ddaline_H
#include <lt/math/math.hpp>
#include <lt/math/Vector2.hpp>
#include <lt/math/Vector3.hpp>
namespace lt {
	class ddaline
	{
	private:
		unsigned int VAO, VBO;
		unsigned int count;

		lt::Vector2<int> a, b;
		lt::Vector3<float> aColor, bColor;
	public:
		ddaline(lt::Vector2<int> _a, lt::Vector3<float> _aColor, lt::Vector2<int> _b, lt::Vector3<float> _bColor);
		~ddaline();
		void Init();
		void Display();
		void Destroy();
	};
}
#endif