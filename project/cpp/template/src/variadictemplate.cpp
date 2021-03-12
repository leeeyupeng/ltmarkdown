#include<iostream>
using namespace std;

void print(){

}

template<typename T,typename... Types>
void print(const T& firstArg,const Types&... args){
    cout<<sizeof...(args) + 1 << " : " << firstArg<<endl;
    print(args...);
}

template<typename... Types>
void print(const Types&... args){
    cout<<sizeof...(args)<<endl;
}



// int main(){
//     print(10,10.01f,"hello","world");
//     return 0;
// }