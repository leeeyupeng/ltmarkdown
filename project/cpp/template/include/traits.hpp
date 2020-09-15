#pragma once
template<typename T> struct traits
{
	typedef T type;
	typedef T type2;
	typedef T type3;
	//T type;
	T type11;
};
template<>
struct traits<float> {
	int type;
};

template<typename T> struct traits2
{
	typedef T type;
	typedef T type2;
	typedef T type3;
};

template<typename PacketType>
struct packet_1 {
	typedef  PacketType type;
};

template<typename T>
struct packet_2 {
	typedef typename packet_1<typename traits<T>::type>::type type;
	typedef typename traits<T>::type type2;
	typename traits<T>::type a;
	typename int a1;
	int a2;
	typename T a3;
};

typedef int INT32;
INT32 a1;
typename INT32 a2;