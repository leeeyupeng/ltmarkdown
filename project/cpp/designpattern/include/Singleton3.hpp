#pragma once
#define CLASSNAME(T) #T
template<typename T>
class Singleton{
private:
    static T m_instance;
public:
    Singleton(){cout<<"Singleton:"<<CLASSNAME(T)<<" constructor"<<endl;}
    ~Singleton(){cout<<"Singleton:"<<CLASSNAME(T)<<" destructor"<<endl;}
    static T* getInstance(){
        return &m_instance;
    }
    friend T;
};

template<typename T>
T Singleton<T>::m_instance=T();
