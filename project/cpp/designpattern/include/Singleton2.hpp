#pragma once
#define CLASSNAME(T) #T
template<class T>
class Singleton{
private:
    static T* m_instance;
public:
    Singleton(){cout<<"Singleton:"<<CLASSNAME(T)<<" constructor"<<endl;}
    ~Singleton(){
        //防止内存泄漏
        free(m_instance);
        m_instance=nullptr;
        cout<<"Singleton:"<<CLASSNAME(T)<<" destructor"<<endl;
    }
    static T* getInstance(){
        return m_instance;
    }
};

template<typename T>
T* Singleton<T>::m_instance=new T();