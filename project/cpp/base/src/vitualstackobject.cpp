#include<iostream>
using namespace std;

namespace vitualstackobject{
    class Base{
    private:
        int base1;
    public:
        Base(){
            cout<<"Base()"<<endl;
        }
        
        Base(const Base &base){
            base1 = base.base1;
            cout<<"Base::Base(const Base &base)"<<endl;
        }

        void print(){
            cout<<"Base::print()"<<endl;
        }

        virtual void virtualprint(){
            cout<<"Base::virtualprint()"<<endl;
        }
    };
    class A:public Base{
    public:
        A(){
            cout<<"A()"<<endl;
        }
        void print(){
            cout<<"A::print()"<<endl;
        }
        virtual void virtualprint(){
            cout<<"A::virtualprint()"<<endl;
        }
    };
    class B:public Base{
    public:
        B(){
            cout<<"B()"<<endl;
        }
        void print(){
            cout<<"B::print()"<<endl;
        }
        virtual void virtualprint(){
            cout<<"B::virtualprint()"<<endl;
        }
    };

}

// using namespace vitualstackobject;
// int main(){
//     //Base base;
//     Base ba = A();
//     //A a;
//     ba.print();
//     ba.virtualprint();

//     A a;
//     a.print();
//     a.virtualprint();

//     Base* ptrba = &a;
//     ptrba->print(); //Base::print()
//     ptrba->virtualprint();//A::virtualprint()

//     return 0;
// }