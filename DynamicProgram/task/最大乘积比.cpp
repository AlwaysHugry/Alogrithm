#include<iostream>
using namespace std;
int num[100];//���������ÿλ���洢����
int Max[1000][1000];//�洢ǰn��������Ϊk�������˻�
int atoi(int start,int end)//��start��endλ����Ϊʮ������
{
    int t=1,sum=0;
    for(int i=start;i<=end;i++)
    {
       sum+=num[start]*t;
       t*=10;
    }
}
void maxSolve(int n,int k)//���ǰ nλ������Ϊk�������˻�
{
    for(int i=k-1;i<n;i++)
    {
        if(Max[i][k-1]==0)
        maxSolve(i,k-1);
        if(Max[i][k-1]*atoi(i+1,n)>Max[n][k])//���߳����˻�,���洢����
        Max[n][k]=Max[i][k-1]*atoi(i+1,n);
    }
}
int main()
{
    int n,k;
    int t=0;
    cin>>n>>k;
    while(n>0)//��ÿ�����ִ洢��������
    {
       num[t]=n%10;
       n/=10;
    }
    for(int i=1;i<=t;i++)
    for(int j=1;j<=k;j++)
    Max[i][j]=0;//��ʼ��
    maxSolve(t,k);
    cout<<Max[t][k];
}