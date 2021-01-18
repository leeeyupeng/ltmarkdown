#include<iostream>
using namespace std;
class Base{
private:
    int base;
public:
    Base(int _base):base(_base){

    }

    void foo(){
        cout<<"Base foo:"<<base<<endl;
    }
};

class Test:public Base
{
private:
    int test;
public:
    Test(int _test,int _base):test(_test),Base(_base){}
    void foo(){
        cout<<"Test foo:"<<test<<endl;
        Base::foo();
    }
};

class Base2{
private:
    int base2;
public:
    Base2(int _base2):base2(_base2){

    }

    virtual void foo(){
        cout<<"Base2 foo:"<<base2<<endl;
    }
};

class Test2:public Base2{
private:
    int test2;
public:
    Test2(int _test2,int _base2):test2(_test2),Base2(_base2){}
    virtual void foo(){
        cout<<"Test2 foo:"<<test2<<endl;
        //Base2:foo();
    }
};

// int main(){
//     Test test=Test(10,1);
//     Base2 test2=Test2(20,2);
//     Base2* test22 = new Test2(20,2);
//     Base2& test222=*test22;
//     test.foo();
//     test2.foo();
//     ((Test2*)(&test2))->foo();
//     //(reinterpret_cast<Test2>)(test2)).foo();
    
//     test22->foo();
//     test222.foo();
//     return 0;
// }