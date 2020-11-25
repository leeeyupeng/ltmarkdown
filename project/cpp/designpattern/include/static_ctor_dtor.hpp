#pragma once
#include<iostream>
using namespace std;

template<typename T>
class static_ctor_dtor{
public:
    struct helper
    {
        helper(){
            cout<<"static_ctor_dtor helper constructor"<<endl;
            T::static_constructor();
        }
        ~helper(){
            cout<<"static_ctor_dtor helper destructor"<<endl;
            T::static_destructor();
        }
    };
protected:
    static helper placeholder;
protected:
    static_ctor_dtor(){
        cout<<"static_ctor_dtor constructor"<<endl;
    }
    ~static_ctor_dtor(){

        cout<<"static_ctor_dtor destruct"<<endl;

    }
public:
    static helper* getHelper(){return &placeholder;}
    // static_ctor_dtor(){
    //     static helper placeholder;
    // }
};

template<typename T>
typename static_ctor_dtor<T>::helper static_ctor_dtor<T>::placeholder;
