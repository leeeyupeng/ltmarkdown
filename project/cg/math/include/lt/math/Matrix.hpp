
#ifndef  _MATRIX_H
#define _MATRIX_H
namespace lt {
	template<class T, unsigned int COL>
	struct vec
	{
	private:
		T cols[COL];
	public:
		inline T& operator[](int index);
	};

	template<class T, unsigned int ROW, unsigned int COL>
	class mat {
		typedef vec<T, COL> RowType;
	private:
		RowType rows[ROW];
	public:
		inline RowType& operator[](int index);
		static const mat Identity();
	};

	template<class T, unsigned int ROW1, unsigned int COL1, unsigned int ROW2, unsigned int COL2>
	typename mat<T, ROW1, COL2> operator* (mat<T, ROW1, COL1> m1, mat<T, ROW2, COL2>);

	template class lt::vec<float, 4>;
	template class lt::mat<float, 4, 4>;
	template typename mat<float, 4, 4> operator* (typename mat<float, 4, 4> m1, typename mat<float, 4, 4>);

	typedef vec<float, 4> Vec_4f;
	typedef mat<float, 4, 4> MATRIX_4x4f;

	template class lt::vec<float, 3>;
	template class lt::mat<float, 4, 3>;
	template class lt::mat<float, 3, 4>;
	template typename mat<float, 4, 4> operator* (typename mat<float, 4, 3> m1, typename mat<float, 3, 4>);
}
#endif