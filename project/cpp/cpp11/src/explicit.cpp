#include<iostream>
using namespace std;


struct Complex{
    int real,imag;
    explicit Complex(int _real,int _imag=0):real(_real),imag(_imag){}
    Complex operator+(const Complex &c){
        return Complex(real+c.real,imag+c.imag);
    }
};

int main_explicit(){
    Complex c11(1,2);
    // Complex c12 = c11 + 2;
    Complex c13{1};
    Complex c14{2,3};
    // Complex c15 = {3,5};
}