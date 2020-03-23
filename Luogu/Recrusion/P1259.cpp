#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n==4)//直接打表
    cout<<"oooo****--"<<endl<<"ooo--***o*"<<endl<<"ooo*o**--*"<<endl<<"o--*o**oo*"<<endl<<"o*o*o*--o*"<<endl<<"--o*o*o*o*";
    else{
        for(int i=n;i>4;i--)
        {
            for(int j=0;j<i;j++)
            cout<<'o';
            for(int j=0;j<i;j++)
            cout<<'*';
            cout<<"--";
            for(int j=0;j<(n-i);j++)
            cout<<"o*";
            cout<<endl;
            for(int j=0;j<i-1;j++)
            cout<<'o';
            cout<<"--";
            for(int j=0;j<i-1;j++)
            cout<<'*';
            cout<<"o*";
            for(int j=0;j<(n-i);j++)
            cout<<"o*";
            cout<<endl;
        }
        cout<<"oooo****--";
        for(int j=0;j<n-4;j++)
        cout<<"o*";
        cout<<endl;
        cout<<"ooo--***o*";
        for(int j=0;j<n-4;j++)
        cout<<"o*";
        cout<<endl;
        cout<<"ooo*o**--*";
        for(int j=0;j<n-4;j++)
        cout<<"o*";
        cout<<endl;
        cout<<"o--*o**oo*";
        for(int j=0;j<n-4;j++)
        cout<<"o*";
        cout<<endl;
        cout<<"o*o*o*--o*";
        for(int j=0;j<n-4;j++)
        cout<<"o*";
        cout<<endl;
        cout<<"--o*o*o*o*";
        for(int j=0;j<n-4;j++)
        cout<<"o*";
        cout<<endl;
    }
}