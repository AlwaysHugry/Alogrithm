#include<iostream>
using namespace std;
int ans=0;
void hanoi(int n,int a,int b,int c)//A移到C,B辅助
{
    ans++;
    if(n>0)
    {
        hanoi(n-1,a,c,b);//先按照规则移动上面的n-1个圆盘到B
        a=0;
        c++;
        hanoi(n-1,b,a,c);//将n-1盘子按照上面的方法移动到C;
    }
}
int main(){
    int n;
    cin>>n;
    hanoi(n,n,0,0);
    cout<<ans;
}