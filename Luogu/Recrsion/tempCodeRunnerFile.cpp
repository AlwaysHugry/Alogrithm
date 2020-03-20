#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
int k[10];
int n;
int str[10];
void dfs(int depth)
{
    if(depth==n+1){
        for(int i=1;i<=n;i++)
        {
            cout<<setw(5)<<str[i];
        }
        cout<<endl;
        return ;
    }
    else{
        for(int i=1;i<=n;i++)
        {
            if(k[i]!=0)
            {
                k[i]=0;
                str[depth]=i;
                dfs(depth+1);
                k[i]++;
            }
        }
    }
}
int main()
{
    cin>>n;
    memset(k,0,sizeof(k));
    for(int i=1;i<=n;i++)
    {
        k[i]=1;
    }
    dfs(1);
}