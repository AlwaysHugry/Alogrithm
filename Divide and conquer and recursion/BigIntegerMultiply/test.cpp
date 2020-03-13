#include<iostream>
#include<cmath>
using namespace std;
long long f(long long t,long long s,int length)//分治
{
    if(length==1) return t*s;
    else{
        long long result=0,result1,result2,result3;
        long long a,b,c,d;
        a=t/(long long)pow(10,length/2);//记录分治因子
        b=t%(long long)pow(10,length/2);
        c=s/(long long)pow(10,length/2);
        d=s%(long long)pow(10,length/2);
        result1=f(b,d,length/2);//解决分问题
        result2=f(a,c,length/2);
        result3=(f(a+b,c+d,length/2)-result1-result2);//此处会发生错误,a+b,c+d可能长度不为length/2;
        return result1+result2*(long long)pow(10,length)+result2*(long long)pow(10,length/2);
    }
}
int main()
{
    long long a,b;
    int length;//记录俩长整数的位数
    cin>>a>>b;
    cin>>length;
    cout<<f(a,b,length);
}