//#include<cstdlib>
//#include"datastructure/Stack.hpp"
//using namespace datastructure;
//#define MALLOCSIZE 64
//template<class T>
//Stack<T>::Stack():size(MALLOCSIZE),top(0),arr(NULL) {
//	arr = (T*)malloc(sizeof(T) * size);
//}
//template<class T>
//Stack<T>::Stack(int _size):size(_size), top(0), arr(NULL) {
//	arr = (T*)malloc(sizeof(T) * size);
//}
//template<class T>
//Stack<T>::~Stack() {
//	free(arr);
//}
//template<class T>
//void Stack<T>::Push(T e) {
//	if (size <= top) {
//		resize(size+ MALLOCSIZE);
//	}
//	arr[top++] = e;
//}
//template<class T>
//void Stack<T>::Pop() {
//	top--;
//}
//template<class T>
//T Stack<T>::Top() {
//	return arr[top-1];
//}
//template<class T>
//bool Stack<T>::Empty() {
//	return top == 0;
//}
//template<class T>
//void Stack<T>::resize(int _size) {
//	arr = (T*)realloc(arr,sizeof(T) * _size);
//	size = _size;
//}
