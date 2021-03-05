#include<iostream>
using namespace std;
#include"Tuple.hpp"

template<int... I>
void apply(Indices<I...>){
    using expand=bool[];
    (void)expand{
        (
            cout<<"get():"<<I<<endl,
            cout<<"testttt"<<endl,
            true
        )...
    };
}

template<int... I>
void apply2(Indices<I...>){
    using expand=bool[];
    void* e[]={
        (
            cout<<"get():"<<I<<endl,
            nullptr
            
        )...
    };
}
// void appletest(){
//     using expand=bool[];
//     (void)expand{
//         (
//             cout<<"get():"<<0<<endl,
//             true
//         )
//         (
//             cout<<"get():"<<1<<endl,
//             true
//         )
//     };
// }
// int main(){
//     auto result = BuildIndices<-1,10>::result{};

//     apply2(result);
//     return 0;
// }