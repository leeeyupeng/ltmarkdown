#include<iostream>
#include<set>
using namespace std;

class Solution{
private:
    int gcd(int a,int b){
        return gcd(b,a%b);
    }

    long long  gcd_ex(long long  a,long long  b,long long  &x,long long  &y){
        if(b == 0){
            x = 1;
            y = 0;
            return a;
        }
        else{
            long long  gcd = gcd_ex(b,a%b,x,y);
            long long  tempx = x;
            x = y;
            y = tempx - (a/b) * y;
            return gcd;
        }
    }
public:
    int solve(long long x,long long  y,long long  m,long long  n,long long  L){
        long long  a = n - m;
        long long  b = L;
        long long  c = x-y;
        long long  x0;
        long long  y0;     
        if(a<0){a = - a;c = -c;}   
        long long  gcd = gcd_ex(a,b,x0,y0);
        if(c%gcd!=0){return -1;}
        long long  ret = x0*(c/gcd);
        ret = (ret%(b/gcd) + b/gcd)%(b/gcd);
        return ret;
    }
};

int main(){
    int x,y,m,n,L;
    cin>>x>>y>>m>>n>>L;
    Solution solution;
    int ret = solution.solve(x,y,m,n,L);
    if(ret == -1){cout<<"Impossible"<<endl;}
    else{cout<<ret<<endl;}
    return 0;
} 