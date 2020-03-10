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