#include<iostream>
using namespace std;

namespace LT{
template<typename T>
class Func_A{
private:
    int a1;
    int a2;
public:
    Func_A():a1(1),a2(2){
        cout<<"Func_A()"<<endl;
        }
    ~Func_A(){
        cout<<"~Func_A()"<<endl;
        }
    template<typename TT>
    Func_A(Func_A<TT>&& a){      
        this->a1 = a.a1;
        this->a2 = a.a2;  
        cout<<"Func_A(Func_A&& a)"<<endl;
    }
    Func_A(Func_A& a){      
        this->a1 = a.a1;
        this->a2 = a.a2;  
        cout<<"Func_A(Func_A& a)"<<endl;
    }
};

template<typename T>
Func_A<T> getfunc_a(){
    return Func_A<T>();
}
}