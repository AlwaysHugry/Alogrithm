#include<iostream>
using namespace std;
char str[1000];//存放排列的数组
int ans=0;//记录次数
int k[1000][2];//存放字符与次数
int n;
int num=0;//元素种数
void dfs(int depth)
{
    if(depth==n+1)//输出
    {
        ans++;//记录次数
        for(int i=0;i<n;i++)
        cout<<str[i];
        cout<<endl;
        return;//结束搜索
    }
    else{
        for(int i=0;i<num;i++)
        {
            if(k[i][1]!=0)//若是有元素没排列过,进行排列
            {
                str[depth-1]=(char)k[i][0];
                k[i][1]--;
                dfs(depth+1);
                k[i][1]++;//注意回溯
            }
        }
    }
}
void check(int t)
{
    for(int i=0;i<num;i++)
    if(t==k[i][0])
    {
        k[i][1]++;
        return ;
    }
    k[num++][0]=t;
    k[num-1][1]=1;
    return;

}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int t;
        char c;
        cin>>c;
        t=c;
        check(t);//检查该字符是否出现过
    }
    dfs(1);
}