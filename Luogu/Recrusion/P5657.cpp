#include<iostream>
#include<cmath>
using namespace std;
void Gray(int n,unsigned long long k)
{
    if(k<=(1ull<<n-1)-1)//有规律可得,在前半部分第一个码为0
    {
        cout<<0;
        if(n-1>0)//剩余部分由Gary(n-1,k)推得
        Gray(n-1,k);
    }
    else{
        cout<<1;
        if(n-1>0)
        Gray(n-1,(1ull<<n-1)-k-1+(1ull<<n-1));//这里数据有毒,直接写1ull>>n会爆
    }
}
int main()
{
    int n;
    unsigned long long k;
    cin>>n>>k;
    Gray(n,k);
}