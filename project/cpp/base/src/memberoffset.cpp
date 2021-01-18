#include<iostream>
using namespace std;
namespace memberoffset{
    class A{
    public:
        int a1;
        int a2;
        string a3;
    };
};

// using namespace memberoffset;
// int main(){
//     int A::* offseta1 = &A::a1;
//     int noffseta1 = reinterpret_cast<int>(*(void**)(&offseta1));
// }