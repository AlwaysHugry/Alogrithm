#include<iostream> 
using namespace std;
typedef int Type;
long long ans=0;
void merge(Type a[],Type b[],int left,int mid,int right)
/*��С�����b������������,
��������ָ��,�ֱ�ָ�������Ӽ��͵Ŀ�ʼ����,
���бȽ�,��С�ķ���b������,ָ������ƶ�*/                                                              
{
    int key1=left,key2=mid;
    int key=0;//��¼b�����Ԫ�ظ���
    while(key!=right-left +1)//�����Ӽ���û������
    {
        if(key1<mid&&key2<right+1)//�����Ӽ��϶�û����
        {
            if(a[key1]>a[key2])//��С��Ԫ�ط���b��,�˴���Ҫע��,ȷ�������,���Ǳ���ȷ�������Ԫ��ʱǰ��û����ȵ�Ԫ��;
            {
                b[key++]=a[key2];
                key2++;
            }
            else{
                b[key++]=a[key1];
                key1++;
                ans+=key2-mid;
            }
        }
        else if(key1==mid){//��һ������������
            b[key++]=a[key2];
            key2++;
        }
        else if(key2==right+1){//�ڶ�������������
            b[key++]=a[key1];
            key1++;
            ans+=key2-mid;
        }
    }
    return ;
}
void copy(Type a[],Type b[],int left,int right)//���ź����b,���Ƶ�a
{
    for(int i=0;i<right-left+1;i++)
    {
        a[left+i]=b[i];
    }
    return ;
}   

void MergeSort(Type a[],int left ,int right)
{
    if(left<right){//����������Ԫ��
       Type b[10000000];
       int i=(left+right)/2;
       MergeSort(a,left,i);//�ֳ��������Ͻ��кϲ�����
       MergeSort(a,i+1,right);
       merge(a,b,left,i+1,right);//�ϲ������ź���ļ��ϵ�b
       copy(a,b,left,right); //����
    }
    return ;
}
int main()
{
    int n;
    cin>>n;
    Type a[n+1];
    for(int i=0;i<n;i++)
    {
       cin>>a[i];
    }
    MergeSort(a,0,n-1);
    cout<<ans;
}