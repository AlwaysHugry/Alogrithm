# 论述题

**2-1 证明Hanoi塔问题的递归算法与非递归算法实际上是一回事。** 
 
*非递归算法实际上是用户通过自定义的栈来模拟系统递归调用工作栈而已,本质还是递归;*
 

**2-3 设a[0:n-1]是已排好序的数组。请改写二分搜索法，使得当搜索元素x不在数组中时，返回小于x的最大元素位置i和大于x的最小元素位置j。当搜索元素在数组中时，i和j相同，均为x在数组中的位置。**  
```
int BinarySearch(int a[],int t,int nam)

{
    int r=nam,l=0;
    while(r!=l+1){
        int m=(l+r)/2;
        if(a[m]==t){
            r=m;
            l=m;
        }
        if(t<a[m])r=m-1;
        else l=m+1;
    }
}
```

**2-5 在用分治法求两个ｎ位大整数ｕ和ｖ的乘积时，将ｕ和ｖ都分割成长度为ｎ/３位的3段。证明可以用5次ｎ/３位整数的乘法求得ab的值。按此思想设计一个求两个大整数乘积的分治算法，并分析算法的计算复杂性（提示：n位的大整数除以一个常数k可以在时间q(n)内完成。符号q所隐含的常数可能依赖于k）**    

*a=a1 * 10^(2/3n)+a2 * 10^(1/3n)+a3;*  
*b=b1 * 10^(2/3n)+b2 * 10^(1/3n)+b3;*

a * b  
= a1b1 * 10^(4/3n)+(a1b2+a2b1) *10^n+(a1b3+a2b2+a3b1)  10^(2/3n)+(a2b3+a3b2) *(1/3n)+a3b3  
  
因此只有五个乘法:M1=a1b1 ,M2a2b2  ,  
M3=(a1+a2+a3)*(b1+b2+b3)

M4=(a1-a2+a3)*(b1-b2+b3)

M5=(a1-2a2+4a3)*(b1-2b2+4b3)  
 得到,  
 a1b2+a2b1=(3M1-12M2+2M3-6M4+M5)/6

 a1b3+a2b2+a3b1=(M3+M4)/2-M1-M2

 a3b2+a2b3=(-3M1+12M2+M3+3M4-M5)/6

 a3b3=M2  
**复杂度:**  
**n=1,T(n)=1;**  
**n>1,T(n)=5*T(n/3)+O(n)**
由master定理,T(n)=O(n^log3,5)=O(N^1.464973);

# 算法实现题

## 2-1 众数问题：

**问题描述：给定含有n个元素的多重集合S，每个元素在S中出现的次数称为该元素的重数。多重集S中重数最大的元素称为众数。例如，S =｛1，2，2，2，3，5｝，则S中的众数是2，其重数是3.**
```  
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int num1,num2,time1=0,time2;//1是存储最大次数的数字,2当前遍历的数字
    int n;
    cin>>n;
    int s[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    sort(s,s+n);
    num2=s[0];
    time2++;
    for(int i=1;i<n;i++)
    {
        if(num2!=s[i]){
            if(time1<time2){
                time1=time2;
                num1=num2;
            }
            num2=s[i];
            time2=1;
        }
        else{
            time2++;
        }
    }
    if(time1<time2){
                time1=time2;
                num1=num2;
            }
    cout<<num1<<" "<<time1;
            
}
```  
## 运行结果:  
6  
1 2 2 3 2 5  
2 3