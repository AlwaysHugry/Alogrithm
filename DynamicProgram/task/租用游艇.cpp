#include<iostream>
using namespace std;
int r[1000][1000];//存储租站之间所需要的花费
int minExpense[1000][1000];//记录两个租站之间最少的花费
int minSolve(int start,int end)
{
    int mins=r[start][end];//初始为直接到达的花费
    for(int i=start+1;i<end;i++)
    {
        if(minExpense[i][end]==0)//如果i-end的最低花费未计算计算,计算并保存
        minSolve(i,end); 
        if(r[start][i]+minExpense[i][end]<mins)//决策出最优结果
        mins=r[start][i]+minExpense[i][end];
    }
    minExpense[start][end]=mins;//将结果储存在数组中
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            cin>>r[i][j];//输入存储租站之间所需要的花费
            minExpense[i][j]=0;
        }
    }
    cout<<minExpense[1][n];
}
