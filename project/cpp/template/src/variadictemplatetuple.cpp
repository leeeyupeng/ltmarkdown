#include<iostream>
#include<functional>
using namespace std;

template<typename... args> struct mytuple;
template<> struct mytuple<>{};