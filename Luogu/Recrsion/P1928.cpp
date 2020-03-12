#include<iostream>
using namespace std;
int f(string s,int key)//time表示输出的次数
{
    while(key<s.length()){
        if(s.at(key)=='[')
        {
            int k,point;
            if(s.at(key+2)-'0'>=0&&s.at(key+2)-'0'<=9)//判断重复的次数是几位数
            {
                k=(s.at(key+1)-'0')*10+(s.at(key+2)-'0');
                key+=3;
            }
            else{
                k=s.at(key+1)-'0';
                key+=2;
            }
            point=key;//确定递归开始的地址
            for(int i=0;i<k;i++)
            key=f(s,point);
           
        }
        else if(s.at(key)==']') 
        {
            key++;
            return key;
            //返回递归结束的地址
        }
        else {
            cout<<s.at(key);
            key++;
        }
    }
}
int main()
{
    string s;
    cin>>s;
    f(s,0);
}