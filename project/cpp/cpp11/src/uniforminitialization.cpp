#include<iostream>
#include<array>
#include<vector>
#include<complex>
#include<algorithm>
using namespace std;


class A{
public:
    A(int a1,float a2){}
};

class B{
public:
    B(int a1,int a2){}
};
void uniforminitialiaztion(){
    int values11[]{1,2,3};
    int values12[]={1,2,3};
    //int values13[](1,2,3);


    vector<int> v11{1,2,3};
    vector<int> v12={1,2,3};
    vector<int> v13(3);

    array<int,3> arr11{1,2,3};
    array<int,3> arr12={1,2,3};

    complex<int> c{1,2};

    A a11(1,2.0f);
    A a12{1,3.0f};
    A a13={2,2.0f};

    // array<int,2> arr21{1,2};
    // B b11=arr21;

    // int* a21={1,2,3};
    initializer_list<int> il{1,2,3};
    const int* a22 = il.begin();
    vector<int> v21(il);
    // vector<int> v22(arr11);
    // int values21[](il);

    auto ret11 = max({1,2,3,4,5});
    auto ret12 = min(il);
}

struct tag1{

};

struct  tag2:tag1
{
};


void testtag(tag1){
    cout<<"testtag(tag1)"<<endl;
}
void testtag(tag2){
    cout<<"testtag(tag2)"<<endl;
}

void testpara(int){
    cout<<"testpara(int)"<<endl;
}

int main_uniforminitialiaztion(){
    uniforminitialiaztion();

    testtag(tag1());
    testtag(tag2());
}