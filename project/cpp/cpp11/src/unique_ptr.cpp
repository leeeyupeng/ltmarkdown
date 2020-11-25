#include<iostream>
#include"unique_ptr.hpp"
using namespace std;
#include"func_a.hpp"
#include<memory>
class Unique_Ptr_Base{
public:
    Unique_Ptr_Base(){
        cout<<"Unique_Ptr_Base()"<<endl;
    }
    virtual ~Unique_Ptr_Base(){
        cout<<"~Unique_Ptr_Base()"<<endl;
    }
    virtual void print(){
        cout<<"Unique_Ptr_Base print()"<<endl;
    }
};
class Unique_Ptr_A:public Unique_Ptr_Base{
private:
    int a1;
    int a2;
public:
    Unique_Ptr_A():a1(1),a2(2){
        cout<<"Unique_Ptr_A()"<<endl;
    }
    ~Unique_Ptr_A(){
        cout<<"~Unique_Ptr_A()"<<endl;
    }
    void setA1(int _a1){a1 = _a1;}
    void setA2(int _a2){a2 = _a2;}
    void print(){
        Unique_Ptr_Base::print();
        cout<<"Unique_Ptr_A print():"<< a1<< " "<<a2<<endl;
    }
};

// template<typename T>
// class Func_A{
// private:
//     int a1;
//     int a2;
// public:
//     Func_A():a1(1),a2(2){
//         cout<<"Func_A()"<<endl;
//         }
//     ~Func_A(){
//         cout<<"~Func_A()"<<endl;
//         }
//     Func_A(Func_A&& a){      
//         this->a1 = a.a1;
//         this->a2 = a.a2;  
//         cout<<"Func_A(Func_A&& a)"<<endl;
//     }
//     Func_A(Func_A& a){      
//         this->a1 = a.a1;
//         this->a2 = a.a2;  
//         cout<<"Func_A(Func_A& a)"<<endl;
//     }
// };

// template<typename T>
// Func_A<T> getfunc_a(){
//     return Func_A<T>();
// }

class STD_Unique_Ptr_A{
public:
    int a1;
    int a2;
    STD_Unique_Ptr_A():a1(1),a2(2){
        cout<<"STD_Unique_Ptr_A()"<<endl;
    }
    ~STD_Unique_Ptr_A(){
        cout<<"~STD_Unique_Ptr_A()"<<endl;
    }
    void print(){
        cout<<"STD_Unique_Ptr_A print():"<<a1<<" "<<a2<<endl;
    }
};

class STD_Share_Ptr_A{
public:
    int a1;
    int a2;
    STD_Share_Ptr_A():a1(1),a2(2){
        cout<<"STD_Share_Ptr_A()"<<endl;
    }
    ~STD_Share_Ptr_A(){
        cout<<"~STD_Share_Ptr_A()"<<endl;
    }
    void print(){
        cout<<"STD_Share_Ptr_A print():"<<a1<<" "<<a2<<endl;
    }
};
int main()
{
    {
        LT::Func_A<int> a4 = LT::getfunc_a<int>();
        LT::Func_A<int> a5(a4);
    }

    {
        LT::unique_ptr<Unique_Ptr_Base> up(LT::make_unique<Unique_Ptr_A>());
        up->print();
        up=(LT::make_unique<Unique_Ptr_A>());
        up->print();

        LT::unique_ptr<Unique_Ptr_Base> up2 = LT::make_unique<Unique_Ptr_A>();
        up2->print();

        std::unique_ptr<STD_Unique_Ptr_A> supa= std::make_unique<STD_Unique_Ptr_A>();
        supa->print();
        supa->a1 = 11;
        supa->a2 = 22;
        supa->print();
        std::unique_ptr<STD_Unique_Ptr_A> supa2 = std::make_unique<STD_Unique_Ptr_A>();
        supa2->print();
        supa2->a1 = 111;
        supa2->a2 = 222;
        supa2->print();
        supa->print();
    }


    {
        std::shared_ptr<STD_Share_Ptr_A> sspa1(new STD_Share_Ptr_A);
        sspa1->print();
        sspa1->a1 = 11;
        sspa1->print();
        cout<<"sspa1.use_count():"<<sspa1.use_count()<<endl;
        std::shared_ptr<STD_Share_Ptr_A> sspa2(sspa1);
        sspa1->a2 =22;
        sspa1->print();
        sspa2->print();
        cout<<"sspa1.use_count():"<<sspa1.use_count()<<endl;
        cout<<"sspa2.use_count():"<<sspa2.use_count()<<endl;
    }

    cout<<"end"<<endl;
    return 0;
}