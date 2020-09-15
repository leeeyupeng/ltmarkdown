namespace lt {
	template<class T>
	inline T Min(T a, T b) {
		return a <= b ? a : b;
	}

	template<class T>
	inline T Min(T a, T b,T c,T d) {
		return Min(Min(a,b),Min(c,d));
	}

	template<class T>
	inline T Max(T a, T b) {
		return a >= b ? a : b;
	}

	template<class T>
	inline void Swap(T& a, T& b) {
		T temp = a;
		a = b;
		b = temp;
	}

}

//using namespace lt;
//template<class T>
//T Min(T a, T b) {
//	return a <= b ? a : b;
//}
//template<class T>
//T Max(T a, T b) {
//	return a >= b ? a : b;
//}