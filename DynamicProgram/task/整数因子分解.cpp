#include<iostream>
using namespace std;
void f(int x)//�г�������ӵ����зֽ���
{
    int i=2;
    while(i<x)//���ҳ���һ������,��������һ���滮
    {
        if(x%i==0)
        {
            cout<<i<<'*';
            f(x/i);
        }
        i++;
    }
    cout<<i<<endl;//�������Ϊ����������滮
}
int main()
{
    int n;
    cin>>n;
    f(n);
}
