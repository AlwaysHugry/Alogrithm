#include <bits/stdc++.h>
using namespace std;
const int maxn=5000;
int dp[maxn][maxn];
char s1[3000],s2[3000];
int dist(int i,int j)
{
    int p1=s1[i-1]-'a';
    int p2=s2[j-1]-'a';
    return abs(p1-p2);
}
int main()
{
 
    memset(dp,0,sizeof(dp));
    gets(s1);
    gets(s2);
    int t;
    scanf("%d",&t);
    int l1=strlen(s1);
    int l2=strlen(s2);
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=l1;i++)
    {
        dp[i][0]=t*i;
    }
    for(int i=1;i<=l2;i++)
    {
        dp[0][i]=t*i;
    }
    for(int i=1;i<=l1;i++)
    {
        for(int j=1;j<=l2;j++)
        {
            dp[i][j]=min(dp[i-1][j-1]+dist(i,j),min(dp[i-1][j]+t,dp[i][j-1]+t));
        }
    }
    printf("%d",dp[l1][l2]);
    return 0;
 
}
 
 
 