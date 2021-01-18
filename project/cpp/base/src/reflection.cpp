#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;


namespace solution{
    class base{

    };
    class A:public base{
    public:
        int a1;
        int a2;
        string a3;
        float a4;
        void print(){
            cout<<"A::print() a1:"<<a1<<" a2:"<<a2<<" a3:"<<a3<<" a4:"<<a4<<endl;
        }
    };

    class B:public base{
    public:
        int b1;
        int b2;
    };

    class C:public base{
    public:
        A a;
        B* b;
    };
};

using namespace solution;
#define OFFSET(CLASS,MEMBER) ((int)(long)&((CLASS*)0)->MEMBER)
namespace reflection{
    typedef base* (*createfunc)();
    struct memberinfo{
        string membername;
        int memberoffset;
        string membertypename;
        memberinfo(string _membername,int _memberoffset,string _membertypename):membername(_membername),memberoffset(_memberoffset),membertypename(_membertypename){}
    };
    struct classinfo{
        string classname;
        createfunc create;
        unordered_map<string,memberinfo*> members;
        classinfo(string _classname,createfunc _create,unordered_map<string,memberinfo*> _members):classname(_classname),create(_create),members(_members){}
        memberinfo* getmember(string membername){
            return members[membername];
        }
    };


    class classmanager{
    private:
        unordered_map<string,classinfo*> classmap;

        friend class A;
        friend class B;
    public:
        classmanager(){
            classmap.insert({"A",new classinfo("A",[](){return (base*)new A();},
                {
                    {"a1",new memberinfo("a1",OFFSET(A,a1),"int")},
                    {"a2",new memberinfo("a2",OFFSET(A,a2),"int")},
                    {"a3",new memberinfo("a3",OFFSET(A,a3),"string")},
                    {"a4",new memberinfo("a4",OFFSET(A,a4),"float")},
                }
            )});
        }

        classinfo* getclassinfo(string classname){
            return classmap[classname];
        }

    };
};

using namespace solution;
using namespace reflection;
reflection::classmanager cmgr;

// int main(){
//     classinfo* classa = cmgr.getclassinfo("A");
//     solution::base* ba = classa->create();
//     A* a = (A*)ba;
//     a->a1 = 1;
//     a->a2 = 2;
//     a->a3= "str3";
//     a->a4 = 0.4f;
//     a->print();
//     (*(int*)(ba+classa->getmember("a1")->memberoffset)) = 11;
//     (*(int*)(ba+classa->getmember("a2")->memberoffset)) = 22;
//     (*(string*)(ba+classa->getmember("a3")->memberoffset)) = "str33";
//     (*(float*)(ba+classa->getmember("a4")->memberoffset)) = 0.44f;

//     a->print();
//     return 0;
// }