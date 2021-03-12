#include<iostream>
#include<vector>
using namespace std;

int main_for(){
    vector<int> v11{1,2,3,4,5,6,7,8,9};
    for(auto i : v11){
        cout<<i<<endl;
    }

    for(auto& i : v11){
        i+=i;
    }

    for(auto i : v11){
        cout<<i<<endl;
    }

    for(int i = 0; i < v11.size(); i++){
        cout<<v11[i]<<endl;
    }
    return 0;
}