#include <iostream>
using namespace std;

template<unsigned long N>
struct binary
{
    static unsigned const value=((binary<N/10>::value * 2) + N%10);
};
template <>
struct  binary<0>
{
    static unsigned const value=0;
};

int main()
{
    cout<<"binary<11011>::value:"<<binary<11011>::value<<endl;
    cout<<"binary<011>::value:"<<binary<11>::value<<endl;
    cout<<"011:"<<0x11<<endl;
    cout<<"binary<100110011>::value:"<<binary<100110011>::value<<endl;

    // int n = 100;
    // cin>>n;
    // cout<<"binary<n>::value:"<<binary<n>::value<<endl;

    const int k = 100;
    cout<<"binary<k>::value:"<<binary<k>::value<<endl;
    return 0;
}

