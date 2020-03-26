#include<iostream>
using namespace std;
int main()
{
    int  n;
    cin>>n;
    int a[n-1],dp[100000];
    int dplength;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    dp[0]=a[0];
    dplength=1;
    for(int i=1;i<n;i++)
    {
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
    cout<<dplength;
}