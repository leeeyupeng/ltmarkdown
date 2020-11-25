#pragma once
#define CLASSNAME(T) #T
template<class T>
class Singleton{    
public:
    Singleton(){cout<<"Singleton:"<<CLASSNAME(T)<<" constructor"<<endl;}
    ~Singleton(){cout<<"Singleton:"<<CLASSNAME(T)<<" destructor"<<endl;}
    static T* getInstance(){
        static T m_instance;
        return &m_instance;
    }
};