#include<iostream>
using namespace std;
int f(int n)
{
	int vis[10000];
	vis[0] = 0;
	vis[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		vis[i] = vis[i - 1] + vis[i - 2];
	}
	return vis[n];
}
int main()
{
	int n;
	cin >> n;
	cout << f(n);
}