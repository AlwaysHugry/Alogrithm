#include<iostream>
using namespace std;
void f(int x)//列出这个因子的所有分解结果
{
    int i=2;
    while(i<x)//先找出第一个因子,并进行下一步规划
    {
        if(x%i==0)
        {
            cout<<i<<'*';
            f(x/i);
        }
        i++;
    }
    cout<<i<<endl;//这个因子为本身则结束规划
}
int main()
{
    int n;
    cin>>n;
    f(n);
}
