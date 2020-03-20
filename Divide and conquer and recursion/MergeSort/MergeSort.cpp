#include<iostream> 
using namespace std;
typedef int Type;
void merge(Type a[],Type b[],int left,int mid,int right)
/*从小到大从b数组中往后排,
声明两个指针,分别指向两个子集和的开始部分,
进行比较,较小的放在b数组中,指针向后移动*/                                                              
{
    int key1=left,key2=mid;
    int key=0;//记录b数组的元素个数
    while(key!=right-left +1)//两个子集合没都排完
    {
        if(key1<mid&&key2<right+1)//两个子集合都没排完
        {
            if(a[key1]>=a[key2])//较小的元素放入b中
            {
                b[key++]=a[key2];
                key2++;
            }
            else{
                b[key++]=a[key1];
                key1++;
            }
        }
        else if(key1==mid){//第一个集合排完了
            b[key++]=a[key2];
            key2++;
        }
        else if(key2==right+1){//第二个集合排完了
            b[key++]=a[key1];
            key1++;
        }
    }
    return ;
}
void copy(Type a[],Type b[],int left,int right)//将排好序的b,复制到a
{
    for(int i=0;i<right-left+1;i++)
    {
        a[left+i]=b[i];
    }
    return ;
}   

void MergeSort(Type a[],int left ,int right)
{
    if(left<right){//至少有两个元素
       Type b[1000];
       int i=(left+right)/2;
       MergeSort(a,left,i);//分成两个集合进行合并排序
       MergeSort(a,i+1,right);
       merge(a,b,left,i+1,right);//合并两个排好序的集合到b
       copy(a,b,left,right); //复制
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
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<' ';
    }
}