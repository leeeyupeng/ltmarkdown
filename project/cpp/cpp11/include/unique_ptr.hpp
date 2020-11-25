#pragma once
#include<iostream>
namespace LT{
template<typename T>
class unique_ptr{
public:
    T* ptr=nullptr;
public:
    unique_ptr(){
        ptr = new T();
    }
    ~unique_ptr(){
        if(ptr!=nullptr){
            delete ptr;
            ptr = nullptr;
        }
    }
    T* operator->(){
        return ptr;
    }
    // unique_ptr(unique_ptr& up){
    //     if(ptr!=nullptr){
    //         delete ptr;
    //         ptr = nullptr;
    //     }
    //     ptr = up.ptr;
    //     up.ptr=nullptr;
    //     std::cout<<"unique_ptr(unique_ptr& up)"<<std::endl;
    // }
    // unique_ptr(unique_ptr&& up){
    //     if(ptr!=nullptr){
    //         delete ptr;
    //         ptr = nullptr;
    //     }
    //     ptr = up.ptr;
    //     up.ptr=nullptr;
    //     std::cout<<"unique_ptr(unique_ptr&& up)"<<std::endl;
    // }
    template<typename UT>
    unique_ptr(unique_ptr<UT>&& up){
        if(ptr!=nullptr){
            delete ptr;
            ptr = nullptr;
        }
        ptr = up.ptr;
        up.ptr=nullptr;
        std::cout<<"unique_ptr(unique_ptr<UT>&& up)"<<std::endl;
    }
    template<typename UT>
    unique_ptr& operator=(unique_ptr<UT>&& up){
        if(ptr!=nullptr){
            delete ptr;
            ptr = nullptr;
        }
        this->ptr = up.ptr;
        up.ptr=nullptr;
        return *this;
    }
};
template<typename T>
unique_ptr<T> make_unique(){
    return unique_ptr<T>();
}
}