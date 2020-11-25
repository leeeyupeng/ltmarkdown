#pragma once
#include"static_ctor_dtor.hpp"
#define CLASSNAME(T) #T
template<class T>
class  Singleton:public static_ctor_dtor<Singleton<T>>{
private:
    static T* m_instance;
public:
    static void static_constructor(){cout<<"Singleton:"<<typeid(T).name()<<" constructor"<<endl;}
    static void  static_destructor(){
        //防止内存泄漏
        delete m_instance;
        m_instance=nullptr;
        cout<<"Singleton:"<<typeid(T).name()<<" destructor"<<endl;
    }
public:
    static T* getInstance(){
        typename static_ctor_dtor<Singleton<T>>::helper* helper = static_ctor_dtor<Singleton<T>>::getHelper();
        if(m_instance == nullptr){
            m_instance = new T();
        }
        return m_instance;
    }
    // template<class T>
    //friend Singleton<T>;
    // template<class T>
    // friend T;
    // friend T;
};

template<typename T>
T* Singleton<T>::m_instance=nullptr;

// template<typename T>
// typename static_ctor_dtor<Singleton<T>>::helper static_ctor_dtor<Singleton<T>>::placeholder;