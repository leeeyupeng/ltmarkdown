#include<iostream>
#include<set>
using namespace std;

class Solution{
private:
    set<long long> us;
public:
    int solve(unsigned long long x,unsigned long long  y,unsigned long long  m,unsigned long long  n,unsigned long long  L){
        x %= L;
        y %= L;
        m %= L;
        n %= L;

        int ret = 0;
        long long key;
        while(true){
            if(x == y){return ret;}
            else{
                key = x<<32 + y;
                if(us.find(key)==us.end()){
                    x=(x+m);
                    if(x>=L){x-=L;}
                    y = (y + n);
                    if(y>=L){y-=L;}
                    ret++;
                }
                else{
                    break;
                }
            }
        }
        return -1;
    }
};

// int main(){
//     int x,y,m,n,L;
//     cin>>x>>y>>m>>n>>L;
//     Solution solution;
//     int ret = solution.solve(x,y,m,n,L);
//     if(ret == -1){cout<<"Impossible"<<endl;}
//     else{cout<<ret<<endl;}
//     return 0;

// } 