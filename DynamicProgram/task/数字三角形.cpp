#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;//行数
    cin>>n;
    int vis[n+5][n+5],dp[n+5][n+5];
    for(int i=1;i<=n;i++)
    for(int j=1;j<=i;j++)
    cin>>vis[i][j];//输入数据
    dp[1][1]=vis[1][1];
    for(int i=2;i<=n;i++)
    for(int j=1;j<=i;j++)
    {
        dp[i][j] = 0;
        if(j<=i-1)
        dp[i][j] = dp[i-1][j]+vis[i][j];
        if(j>1)
        dp[i][j] = max(dp[i][j],dp[i-1][j-1]+vis[i][j]);
    }
    int max1=0;
    for(int i=1;i<=n;i++)//找出最后一行最大值
    {
        max1= max(max1,dp[n][i]);
    }
    cout<<max1;
}