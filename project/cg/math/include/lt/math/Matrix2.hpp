
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
	public:
		typedef vec<T, COL> RowType;
	private:
		RowType rows[ROW];
	public:
		inline RowType& operator[](int index);
		static const mat Identity();
	};

	template<class T, unsigned int ROW1, unsigned int COL1, unsigned int ROW2, unsigned int COL2>
	typename mat<T, ROW1, COL2> operator* (mat<T, ROW1, COL1> m1, mat<T, ROW2, COL2>);

	template<class T, unsigned int COL>
	T& lt::vec<T, COL>::operator[](int index) {
		return cols[index];
	}
	template<class T, unsigned int ROW, unsigned int COL>
	typename lt::mat<T, ROW, COL>::RowType& lt::mat<T, ROW, COL>::operator[](int index) {
		return rows[index];
	}
	template<class T, unsigned int ROW, unsigned int COL>
	const lt::mat<T, ROW, COL> lt::mat<T, ROW, COL>::Identity() {
		return lt::mat<T, ROW, COL>();
	}

	template<class T, unsigned int ROW1, unsigned int COL1, unsigned int ROW2, unsigned int COL2>
	typename mat<T, ROW1, COL2> operator* (typename mat<T, ROW1, COL1> m1, typename mat<T, ROW2, COL2>) {
		//typename mat<T, ROW1, COL1>::RowType* row = m1.rows;
		return mat<T, ROW1, COL2>();
	}

	typedef vec<float, 4> Vec_4f;
	typedef mat<float, 4, 4> MATRIX_4x4f;
}
#endif