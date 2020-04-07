#include<iostream>
#include<vector>
using namespace std;
int n,a[100005];//输入序列
int dp[100005];//dp[i]表示当前长度下末尾最小元素
int dplength=0;//记录dp长度
int depth=0;//记录v序列长度
vector<int>v[100005]//存储可能组成上升序列的元素
int main()
{
    cin>>n;
    dp[0]=0;
    dplength++;
    cin>>a[0];

    for(int i=1;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>dp[dplength-1])
        {
            dp[dplength++]=a[i];
        }
        else for(int j=0;j<dplength;j++)
        {
            if(a[i]<dp[j])
            {
                dp[j]=a[i];
                break;
            }
        }
    }
}