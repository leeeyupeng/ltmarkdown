#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
class dynbase;
typedef dynbase* (*createfunc)();
struct classinfo{
    string classname;
    createfunc create;
    classinfo(){

    }
    classinfo(string _classname,createfunc _create):classname(_classname),create(_create){
    }
    
    classinfo(const classinfo& info){
        this->classname = info.classname;
        this->create = info.create;
    }
};

class ClassManager{
private:
    unordered_map<string,classinfo> classmap;
public:
    void Register(classinfo info){
        classmap.insert({info.classname,info});
    }

    dynbase* create(string classname){
        classinfo info1(classmap[classname]);//这一行 classinfo 没有无参构造函数的话，会编译报错
        unordered_map<string,classinfo>::iterator ite = classmap.find(classname);
        classinfo info = ite->second;
        createfunc func =  info.create;
        return func();
        //return nullptr;
    }
};

class dynbase{

};

class A:dynbase{
public:
    A(){
        cout<<"A()"<<endl;
    }
    void print(){
        cout<<"class A"<<endl;
    }
    static A* create(){
        return new A();
    }
};
class B:dynbase{
public:
    B(){
        cout<<"B()"<<endl;
    }
    void print(){
        cout<<"class B"<<endl;
    }
    static B* create(){
        return new B();
    }
};
