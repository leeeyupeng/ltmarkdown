#include<iostream>
using namespace std;
#include"static_ctor_dtor.hpp"
#include"Singleton.hpp"


class TestA:public Singleton<TestA>{
private:
    int a1;
    int a2;
private:
    TestA():a1(1),a2(2){
        cout<<"TestA constructor"<<endl;
    }
    ~TestA(){

        cout<<"TestA destruct"<<endl;

    }

public:
    friend void Singleton<TestA>::static_destructor();
    friend TestA* Singleton<TestA>::getInstance();
    // friend Singleton<TestA>;
    void setA1(int _a1){a1 = _a1;}
    void setA2(int _a2){a2 =_a2;}
    int getA1(){return a1;}
    int getA2(){return a2;}
    void print(){
        cout<<"TestA a1:"<<a1<<" a2:"<<a2<<endl;
    }
    static void teststatic(){}
};

class TestA;

class TestB{
private:
    int b1;
    int b2;
private:
    TestB():b1(1),b2(2){
        cout<<"TestB constructor"<<endl;
    }
    ~TestB(){

        cout<<"TestB destruct"<<endl;

    }
public:
    friend Singleton<TestB>;
};

class TestStatic:public static_ctor_dtor<TestStatic>{
public:
    static void static_constructor(){cout<<"TestStatic:"<<" constructor"<<endl;}
    static void  static_destructor(){
        cout<<"TestStatic"<<" destructor"<<endl;
    }
};

// int main()
// {
//     cout<<"start"<<endl;
//     //TestStatic testStatic;
//     //typename static_ctor_dtor<TestStatic>::helper* helper;
//     //typename static_ctor_dtor<TestStatic>::helper* helper = TestStatic::getHelper();
//     TestA* a = TestA::getInstance();
//     a->print();
//     a->setA1(11);
//     a->setA2(22);
//     a->print();
//     TestA* a2 = TestA::getInstance();
//     a2->print();
//     TestA::teststatic();

//     TestB* b = Singleton<TestB>::getInstance();
//     // TestB* b2 = new TestB();
//     // TestB b3;
//     return 0;
// }