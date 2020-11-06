#include<iostream>
using namespace std;
#include"lt/math/Matrix.hpp"
using namespace lt;
template<class T, unsigned int COL>
T& lt::vec<T, COL>::operator[](int index) {
	return cols[index];
}
template<class T, unsigned int ROW, unsigned int COL>
typename lt::mat<T,ROW,COL>::RowType& lt::mat<T, ROW, COL>::operator[](int index){
	return rows[index];
}
template<class T, unsigned int ROW, unsigned int COL>
const lt::mat<T,ROW,COL> lt::mat<T, ROW, COL>::Identity() {
	return lt::mat<T, ROW, COL>();
}

template<class T, unsigned int ROW1, unsigned int COL1, unsigned int ROW2, unsigned int COL2>
typename mat<T, ROW1, COL2> lt::operator* (typename mat<T, ROW1, COL1> m1, typename mat<T, ROW2, COL2>) {
	return mat<T, ROW1, COL2>();
}