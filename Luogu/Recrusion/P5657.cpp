#include<iostream>
#include<cmath>
using namespace std;
void Gray(int n,unsigned long long k)
{
    if(k<=(1ull<<n-1)-1)//�й��ɿɵ�,��ǰ�벿�ֵ�һ����Ϊ0
    {
        cout<<0;
        if(n-1>0)//ʣ�ಿ����Gary(n-1,k)�Ƶ�
        Gray(n-1,k);
    }
    else{
        cout<<1;
        if(n-1>0)
        Gray(n-1,(1ull<<n-1)-k-1+(1ull<<n-1));//���������ж�,ֱ��д1ull>>n�ᱬ
    }
}
int main()
{
    int n;
    unsigned long long k;
    cin>>n>>k;
    Gray(n,k);
}