#pragma once

template<typename T>
struct A;

template<>
struct A<int> {
};

template<typename T>
struct AA : A<T> {};

