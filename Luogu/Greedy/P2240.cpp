#include<iostream>
#include<algorithm>
using namespace std;
struct value{
    int weight;//质量
    int value;//总价值
    double val;//性价比
};
bool cmp(value a,value b)
{
    return a.val > b.val;//按性价比降序排序
}
int main()
{
    int N,T;//T为背包容量
    cin>>N>>T;
    value w[N+1];//记录每堆金币的信息
    double wealth = 0;//记录能拿走的财富
    for(int i=0;i<N;i++)
    {
        cin>>w[i].weight>>w[i].value;//输入每堆金币质量与价值
        w[i].val = w[i].value / (double)w[i].weight;
    }
    sort(w,w+N,cmp);
    int i = 0;
    while(T>0&&i<N){
        if(T>=w[i].weight)
        {
            wealth += w[i].value;
            T -= w[i].weight;
        }
        else{
            wealth += w[i].val * T;
            T = 0;
        }
        i++;
    }
    printf("%.2f",wealth);
}