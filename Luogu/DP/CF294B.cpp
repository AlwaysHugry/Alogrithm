#include<iostream>
#include<algorithm>
using namespace std;
int n;//书本数
int t[105],w[105];//厚度,宽度
int dp[105][205];//dp[i][j]考虑前i本书,抽出j厚度和的书放在上层
int all[105];//记录前i本书的厚度和
int main()
{
    cin>>n;
    int sum=0;//所有书的厚度和
    for(int i=1;i <= n;i++)
    {
        cin>>t[i]>>w[i];
        sum += t[i];
        all[i] = sum;
    }
    for(int i = 0;i < 105;i++)
    dp[i][0] = 0;
    for(int j = 1;j <= sum;j++)//拿出j厚度和的书放在上层
    {
        int i = 0;
        while(all[i] < j)
        {
            dp[i][j] =  1000005;//厚度和不够时,置为最大值
            i++;
        }
        for(;i <= n;i ++)
        {
            if(j < t[i])//这本书厚度超过允许的厚度和
            dp[i][j] = dp[i-1][j];
            else//没有超过 
            dp[i][j] = min(dp[i-1][j] , dp[i-1][j-t[i]]+w[i]);
        }
    }
    int i = sum;
    while(dp[n][i] > sum - i)//找到符合上层长度小于等于下层长度的条件
    {
        i--;
    }
    cout<<sum - i;
}
