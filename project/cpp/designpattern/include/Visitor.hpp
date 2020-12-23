#include<iostream>
#include<string>
using namespace std;
#include"Tuple.hpp"

template<typename T>
struct data{
    T value;
};

struct Ivisitor{
    virtual void visit(int data){}
    virtual void visit(string data){}

    virtual void visit(data<int> data){}
    virtual void visit(data<string> data){}
};
struct Idatacontainerbase{
    virtual ~Idatacontainerbase(){}
    virtual int getdatacount() const=0;
    virtual void visit(Ivisitor &visitor) const = 0;
};

template<typename Datas>
struct  datacontainerbase1:Idatacontainerbase
{
    Datas datas;
};

struct Visitor1
{

};
