## ���⣺
����һ������Ϊn������a1,a2,...,an������Ҫ����n��Ԫ�طֳ����ࣺ1��2��3��

1:���е�����������ж����������Ԫ��

2:�е������е�����������а������Ԫ��

3:���е�����������ж��������Ԫ��

## �����ʽ��
��һ�а���һ��������n����ʾ���еĳ��ȡ��ڶ��а���n��������a1,a2,...,an����ʾ�����е�Ԫ�ء�

## �����ʽ��
һ�У�����һ������Ϊn�ġ���1,2,3����������ɵ��ַ�������i�����ֱ�ʾai�������

## ���ݷ�Χ��
1��n��$10^5$

1��ai��$10^5$

## �����������   
���� 1  4  
���   3   
����  4  1 3 2 5  
���  3223  
����  4  1 5 2 3  
���  3133  


## �ⷨ
���ǿ��Բ���LIS�ĵڶ��ֽⷨ,����Ľ�,����׷�ٱ���;ȷ��ÿ����������е�ÿ��Ԫ��;  
�ο�:
```
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 100005
using namespace std;
int n,a[maxn];//��������
int dp[maxn];//dp[i]����ǰ����Ϊi������������ĩβԪ�ص���Сֵ
int len=0;//��������LIS�ĳ���
int sign[maxn];//����Ԫ���������
vector<int>layer[maxn];//�ֲ����飬һ����len�㡣layer[i]�еĵ��ʾ��ЩԪ�أ�����ЩԪ�ؽ�β������������г���Ϊi
inline int bins(int i,int val){
    int l=0,r=layer[i].size()-1;
    while(l<r){
        int m=(l+r)>>1;
        if(a[layer[i][m]]>=val)l=m+1;
        else r=m;
    }
    return l;
}
int main(){
    scanf("%d",&n);
    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        int length=lower_bound(dp,dp+n+1,a[i])-dp;//O(nlogn)��LIS
        dp[length]=min(dp[length],a[i]);
        //length��ʾ�Ը�Ԫ�ؽ�β������������еĳ���
        layer[length].push_back(i);//���뵽�ֲ�����
        len=max(len,length);//�����������е�LIS����
    }
    for(int i=1;i<=n;i++)sign[i]=1;//��ʼ��ȫ��Ϊ��1�࣬���κ�LIS������������
    if(layer[len].size()==1)sign[layer[len][0]]=3;
    else for(int i=0;i<layer[len].size();i++)sign[layer[len][i]]=2;
    for(int i=len;i>=2;i--){//������ֲ����飬һ��һ����ǰ��
        for(int j=0;j<layer[i].size();j++){//ö�ٵ�ǰ������е�
            int bh=layer[i][j];//��ı��
            if(sign[bh]>1){//�����ǰ�ڵ������ǰ��չ������LIS������ǰ�㣩
                int l=bins(i-1,a[bh]);//���ֲ��ң���չ�Ľڵ��������е�ֵ����С�ڵ�ǰ�ڵ㣬���ܱ�֤LIS�ϸ����
                int r=lower_bound(layer[i-1].begin(),layer[i-1].end(),bh)-layer[i-1].begin()-1;//���ֲ��ң���չ�ĵ��ű���С�ڵ�ǰ���ţ������ǡ����С�
                //��ǰ�����չ����ǰһ��ĵ�ķ�Χ������[l,r]
                for(int k=l;k<=r;k++)sign[layer[i-1][k]]=2;//���ϱ�ǣ��ýڵ��ܹ�����չ��˵��һ����������������ĳ��LIS�����õ�
            }
        }
        //��ǰ���ܹ���չ����ǰһ��ĵ��ǵ�ǰ�����е�����չ����ǰһ��Ľڵ�Ĳ���
        int cnt=0,pos=0;
        for(int j=0;j<layer[i-1].size();j++)if(sign[layer[i-1][j]]==2){
            cnt++;
            pos=j;
        }
        if(cnt==1)sign[layer[i-1][pos]]=3;//����ò����п���չ�ĵ�ֻ����ǰһ������չ��һ���ڵ㣬˵������ڵ�������LIS�ıؾ��ڵ㡣
    }
    for(int i=1;i<=n;i++)printf("%d",sign[i]);//�����ո��ӡ
    return 0;
}
```