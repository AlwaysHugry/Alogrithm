#include<iostream>
using namespace std;
int num[100];//将这个数的每位数存储起来
int Max[1000][1000];//存储前n个数划分为k部分最大乘积
int atoi(int start,int end)//将start到end位数化为十进制数
{
    int t=1,sum=0;
    for(int i=start;i<=end;i++)
    {
       sum+=num[start]*t;
       t*=10;
    }
}
void maxSolve(int n,int k)//求解前 n位数划分为k部分最大乘积
{
    for(int i=k-1;i<n;i++)
    {
        if(Max[i][k-1]==0)
        maxSolve(i,k-1);
        if(Max[i][k-1]*atoi(i+1,n)>Max[n][k])//决策出最大乘积,并存储起来
        Max[n][k]=Max[i][k-1]*atoi(i+1,n);
    }
}
int main()
{
    int n,k;
    int t=0;
    cin>>n>>k;
    while(n>0)//将每个数字存储在数组中
    {
       num[t]=n%10;
       n/=10;
    }
    for(int i=1;i<=t;i++)
    for(int j=1;j<=k;j++)
    Max[i][j]=0;//初始化
    maxSolve(t,k);
    cout<<Max[t][k];
}