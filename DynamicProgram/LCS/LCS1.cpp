#include<iostream>
#include<string.h>
using namespace std;
char str1[10005],str2[10005];
int dp[10005][10005];
int main()
{
    cin>>str1>>str2;
    int maxLength = 0;
    int tip1,tip2;
    for(int i=0;i<strlen(str1);i++)
    for(int j=0;j<strlen(str2);j++)
    {
        if(str1[i] != str2[j])//不相同则为0
        dp[i][j] == 0;
        else{
            if(i==0||j==0)//dp[i-1][j-1]不存在
            dp[i][j] = 1;
            else dp[i][j] = dp[i-1][j-1] + 1;//长度加一
            if(maxLength < dp[i][j])
            {
                maxLength = dp[i][j];//更新最长公共子串长度
                tip1 = i;//记录最大公共子串结尾序号
            }
        }
    }
    cout<<maxLength<<endl;
    for(int i=tip1-maxLength+1;i!=tip1+1;i++)
    cout<<str1[i];
}