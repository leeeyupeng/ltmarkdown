#include<iostream>
using namespace std;

template<class T>
class CFinalClassMixin{
private:
    CFinalClassMixin(){
        cout<<"CFinalClassMixin()"<<endl;
    }
    ~CFinalClassMixin(){
        cout<<"~CFinalClassMixin()"<<endl;
    }
    friend T;
};