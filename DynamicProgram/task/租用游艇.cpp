#include<iostream>
using namespace std;
int r[1000][1000];//�洢��վ֮������Ҫ�Ļ���
int minExpense[1000][1000];//��¼������վ֮�����ٵĻ���
int minSolve(int start,int end)
{
    int mins=r[start][end];//��ʼΪֱ�ӵ���Ļ���
    for(int i=start+1;i<end;i++)
    {
        if(minExpense[i][end]==0)//���i-end����ͻ���δ�������,���㲢����
        minSolve(i,end); 
        if(r[start][i]+minExpense[i][end]<mins)//���߳����Ž��
        mins=r[start][i]+minExpense[i][end];
    }
    minExpense[start][end]=mins;//�����������������
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            cin>>r[i][j];//����洢��վ֮������Ҫ�Ļ���
            minExpense[i][j]=0;
        }
    }
    cout<<minExpense[1][n];
}
