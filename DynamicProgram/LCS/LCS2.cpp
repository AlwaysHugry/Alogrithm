#include<iostream>
#include<string.h>
using namespace std;
char str1[10005],str2[10005];
int dp[10005][10005],p[10005][10005];//p[i][j]记录转移的方法,便于回溯
int main()
{
    cin>>str1+1>>str2+1;//从1地址开始
    int maxLength = 0;
    int tip1,tip2;
    for(int i=0;i<=strlen(str1);i++)
    dp[i][0] = 0;
    for(int j=0;j<=strlen(str2);j++)
    dp[0][j] = 0;
    for(int i=1;i<=strlen(str1+1);i++)
    for(int j=1;j<=strlen(str2+1);j++)
    {
        if(str1[i] == str2[j])
        {
            p[i][j] = 1;
            dp[i][j] = dp[i-1][j-1] + 1;
            if(maxLength < dp[i][j])
            {
                maxLength = dp[i][j];//更新最长公共子串长度
                tip1 = i;//记录最大公共子串结尾序号
                tip2 = j;
            }
        }
        else
        {
            if (dp[i-1][j] >= dp[i][j-1])
            {
                p[i][j] = 2;
                dp[i][j] = dp[i-1][j];
            }
            else{
                p[i][j] = 3;
                dp[i][j] = dp[i][j-1];
            }
        }
    }
    string s="";
    while(maxLength!=0)//沿着状态转移的路线回溯出序列
    {
        if(p[tip1][tip2]==1)
        { 
            s = str1[tip1] + s;
            tip1--;
            tip2--;
            maxLength--;
        }
        if(p[tip1][tip2]==2)
        { 
            tip1--;
        }
        if(p[tip1][tip2]==3)
        { 
            tip2--;
        }
    }
    cout<<s;
}