#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int ans=0;
    int a[n+1];//���������
    int dp[n+1];//�洢״̬
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    dp[0]=1;
    for(int i=1;i<n;i++)
    {
        int max=0;
        for(int j=0;j<i;j++)
        {
            if(a[j]<a[i]&&dp[j]>max)
            max=dp[j];
        }
        dp[i]=max+1;
        if(dp[i]>ans)
        ans=dp[i];
    }
    cout<<ans;
}