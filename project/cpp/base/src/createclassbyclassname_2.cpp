#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

namespace createclassbyclassname_2{
    class base;
    struct classinfo;
    typedef base* (*createfunc)();
    void Register(classinfo* _classinfo);
    base* create(string _classname);
    struct classinfo{
        string classname;
        createfunc create;
        classinfo(string _classname,createfunc _create):classname(_classname),create(_create){
            Register(this);
        }
    };

    unordered_map<string,classinfo*> classmap;
    void Register(classinfo* _classinfo){
        classmap.insert({_classinfo->classname,_classinfo});
    }
    base* create(string _classname){
        return classmap[_classname]->create();
    }

    class base{
    private:
        int base1;
    private:
        static classinfo* m_classinfo;
    };
    class A:public base{
    private:
        static classinfo* m_classinfo;
    public:
        A(){
            cout<<"A()"<<endl;
        }
    };

    class B:public base{
    private:
        static classinfo* m_classinfo;
    public:
        B(){
            cout<<"B()"<<endl;
        }
    };

    classinfo* base::m_classinfo = new classinfo("base",[](){return new base();});
    classinfo* A::m_classinfo = new classinfo("A",[](){return (base*)new A();});
    classinfo* B::m_classinfo = new classinfo("B",[](){return (base*)new B();});
}
// using namespace createclassbyclassname_2;
// int main(){
//     base* base = create("A");
//     B* b = (B*)create("B");
//     return 0;
// }