#include<iostream>
#include<vector>
using namespace std;
int n,a[100005];//��������
int dp[100005];//dp[i]��ʾ��ǰ������ĩβ��СԪ��
int dplength=0;//��¼dp����
int depth=0;//��¼v���г���
vector<int>v[100005]//�洢��������������е�Ԫ��
int main()
{
    cin>>n;
    dp[0]=0;
    dplength++;
    cin>>a[0];

    for(int i=1;i<n;i++)
    {
        cin>>a[i];
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
}