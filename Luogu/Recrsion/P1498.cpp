/*
    need to debug;
*/
#include<iostream>
using namespace std;
char s[3000][3000];//用于存储图形
void toRight(int n)//向右复制
{
    for(int i=0;i<4*n;i++)
    for(int j=0;j<2*n;j++)
    s[4*n+i][j]=s[i][j]; 
} 
void toUp(int n)//向上复制
{
    for(int i=0;i<4*n;i++)
    for(int j=0;j<n;j++)
    s[2*n+i][j+2*n]=s[i][j];
}
int main()
{
    for(int i=0;i<3000;i++)
    for(int j=0;j<3000;j++)
    s[i][j]=' ';//初始化
    int  n;
    int k=1;//用以记录图形规模
    cin>>n;
    s[0][0]='/';
    s[0][1]='-';
    s[0][2]='-';
    s[0][3]='\\';
    s[1][1]='/';
    s[1][2]='\\';//构造第一个图形,用以递推出更高阶的图形
    if(n>=2)
    {
        for(int i=1;i<n;i++)
        {
            toRight(k);
            toUp(k);//通过复制得到高一阶的图形
            k*=2;
        }
    }
    for(int i=2*k-1;i>=0;i--)
    {
        for(int j=0;j<2*k+i;j++)
        cout<<s[i][j];
        cout<<endl;
    }
}