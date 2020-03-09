#include<iostream>
#include<algorithm>
using namespace std;
int BinarySearch(int a[],int t,int num)
{
    int r=num,l=0;
    while(r>=l){
        int m=(l+r)/2;
        if(a[m]==t)return m;
        if(t<a[m])r=m-1;
        else l=m+1;
    }
}
int main()
{ 
     int num,t;
     cin>>num;
     int a[num+1];
     for(int i=0;i<num;i++)
     cin>>a[i];
     sort(a,a+num);
     cin>>t;
     cout<<BinarySearch(a,t,num);
}