#include<iostream>
using namespace std;
//如何让类不能被继承
#include"CFinalClassMixin.hpp"
class parent{
public:
    parent(){
        cout<<"parent()"<<endl;
    }
    ~parent(){
        cout<<"~parent()"<<endl;
    }
};

class child:public parent,public virtual CFinalClassMixin<child>{
    public:
    child(){
        cout<<"child()"<<endl;
    }
    ~child(){
        cout<<"~child()"<<endl;
    }
};

// class grandchild:public child{
//     public:
//     grandchild(){
//         cout<<"grandchild()"<<endl;
//     }
//     ~grandchild(){
//         cout<<"grandchild()"<<endl;
//     }
// };

int main()
{
    parent p;
    child c;
    // grandchild gc;
    return 0;
}