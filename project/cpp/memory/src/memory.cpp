#include<iostream>
#include<assert.h>
using namespace std;

#include"memory.hpp"
class Memory_A{
private:
    int a1;
    int a2;
public:
    Memory_A():a1(1),a2(2){
        cout<<"Memory_A()"<<endl;
    }
    ~Memory_A(){
        cout<<"~Memory_A()"<<endl;
    }
};
class Memory_B{
private:
    int b1;
    float b2;
    char b3;
    //char b4;
    int b5;
public:
    Memory_B():b1(1),b2(2),b3(0){
        cout<<"Memory_B()"<<endl;
    }
    ~Memory_B(){
        cout<<"~Memory_B()"<<endl;
    }
};

class Memory_C{
private:
    char c1;
    char c2;
    // char c3;
    // char c4;
    int c5;
    int c6;
public:
    Memory_C():c1(1),c2(2),c5(0),c6(0){
        cout<<"Memory_C()"<<endl;
    }
    ~Memory_C(){
        cout<<"~Memory_C()"<<endl;
    }
};

class Memory_D{
private:
    char d1[96];
    int d2[100];
public:
    Memory_D(){
        cout<<"Memory_D()"<<endl;
    }
    ~Memory_D(){
        cout<<"~Memory_D()"<<endl;
    }
};

class Memory_E{
private:
    int d1[100];
    char d2[100];
public:
    Memory_E(){
        cout<<"Memory_E()"<<endl;
    }
    ~Memory_E(){
        cout<<"~Memory_E()"<<endl;
    }
};

class Memory_F{
private:
    int d1[1000];
    char d2[1000];
public:
    Memory_F(){
        cout<<"Memory_F()"<<endl;
    }
    ~Memory_F(){
        cout<<"~Memory_F()"<<endl;
    }
};

int main(){
    cout<<"sizeof(Memory_A):"<<sizeof(Memory_A)<<endl;
    cout<<"sizeof(Memory_B):"<<sizeof(Memory_B)<<endl;
    cout<<"sizeof(Memory_C):"<<sizeof(Memory_C)<<endl;
    cout<<"sizeof(Memory_D):"<<sizeof(Memory_D)<<endl;
    cout<<"sizeof(Memory_E):"<<sizeof(Memory_E)<<endl;
    cout<<"sizeof(Memory_F):"<<sizeof(Memory_F)<<endl;

    cout<<"sizeof(void*):"<<sizeof(void*)<<endl;
    cout<<"sizeof(int):"<<sizeof(int)<<endl;

    int size;
    void*  ptr0=malloc(100);
    int* ptr;
    void*  ptr1=malloc(67108864);
    void*  ptr2=malloc(67108864);
    void*  ptr3=malloc(67108864);
    LT::memory memorymanager;
    int counter = 100000;
    while(counter>0){
        counter--;
        size = rand()% MAXBLOCK;
        //memorymanager.malloc(size);
        if(size<=2){continue;}
        ptr=(int*)malloc(size*sizeof(int));
        (*ptr) = 11;
        (*(ptr+(size-1))) = 11;
        for(int i = 0; i < size; i ++){
            (*(ptr+(size))) = 11+i;
        }
        assert(ptr);
    }
    int*  ptr4=(int*)malloc(67108864);
    (*ptr4) = 11;
    (*(ptr4+1000)) = 1111;
    cout<<"(*ptr4):"<<(*ptr4)<<endl;
    cout<<"(*(ptr4+1000)):"<<(*(ptr4+1000))<<endl;
    return 0;
}