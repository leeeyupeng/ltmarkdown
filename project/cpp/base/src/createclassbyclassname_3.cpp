#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
namespace createclassbyclassname_3{
    class base;
    typedef base* (*createfunc)();
    struct classinfo{
        string classname;
        createfunc create;
        classinfo(string _classname,createfunc _create):classname(_classname),create(_create){}
    };

    class base{

    };
    class A:public base{
    public:
        A(){
            cout<<"A()"<<endl;
        }
    };
    class B:public base{
    public:
        B(){
            cout<<"B()"<<endl;
        }
    };

    class A;
    class B;
    class classmanager{
    private:
        unordered_map<string,classinfo*> classmap;
    public:
        classmanager(){
            classmap.insert({"A",new classinfo("A",[](){return (base*)new A();})});
            classmap.insert({"B",new classinfo("B",[](){return (base*)new B();})});
        }

        base* create(string _classname){
            return classmap[_classname]->create();
        }
    };

};

// using namespace createclassbyclassname_3;
// classmanager cmgr;
// int main(){
//     base* a=cmgr.create("A");
//     B* b = (B*)cmgr.create("B");

//     return 0;
// }