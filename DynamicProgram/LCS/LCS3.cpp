#include <iostream>
#include <stdio.h>
#include <memory.h>
using namespace std;
 
#define LEN 100005
 
int a[LEN], b[LEN];
int loc[LEN], n;
 
void calLoc()
{
    int i;
	
	for(i = 1; i <= n; i++)
		loc[b[i]] = i;
}
 
int LIS()
{
    int i, k, l, r, mid; 
	
	a[1] = b[1], k = 1;
	for(i = 2; i <= n; i++)
	{
		if(a[k] < b[i]) a[++k] = b[i];
		else {
			l = 1; r = k;
			while(l <= r)
			{
				mid = ( l + r ) / 2;
				if(a[mid] < b[i]) 
					l = mid + 1;
				else  
					r = mid - 1;
				
			}
			a[l] = b[i];
		}
	}
	return k;
}
 
int main()
{
    int i;
	
	while(scanf("%d", &n) != EOF)
	{
		for(i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for(i = 1; i <= n; i++)
			scanf("%d", &b[i]);
		calLoc();
        for(i = 1; i <= n; i++)
		b[i] = loc[a[i]];
		printf("%d\n", LIS());
    }
	return 0;
}