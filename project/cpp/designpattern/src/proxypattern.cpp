#include<iostream>
using namespace std;
class Subject{
public:
    virtual void display(){
        cout<<"subject display()"<<endl;
    }
};
class RealSubject:Subject{
public:
    virtual void display(){
        //Subject::display();
        this->Subject::display();
        cout<<"RealSubject display()"<<endl;
    }
};
class ProxySubject{
private:
    RealSubject realsubject;
public:
    virtual void display(){
        cout<<"ProxySubject display() start"<<endl;
        realsubject.display();
        cout<<"ProxySubject display() end"<<endl;
    }
};
// int main()
// {
//     ProxySubject ps;
//     ps.display();
//     return 0;
// }