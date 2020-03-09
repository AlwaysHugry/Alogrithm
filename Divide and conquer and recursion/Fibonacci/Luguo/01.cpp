#include<iostream>
#include<cmath>
using namespace std;

int main() {
        int n,
        k;
        cin >> n >> k;
        long long f[n + 5];
        f[0] = 1;

       if (n > k) {
            for (int i = 1; i <= k; i++) {
                f[i] = 0;
                for (int j = 0; j < i; j++)
                f[i] += f[j];
            }
            for (int i = k + 1; i <= n; i++) {
                f[i] = 0;
                for (int j = 1; j <= k; j++) {
                    f[i] += f[i - j];
                }
            }
        }
       else {
            for (int i = 1; i <= n; i++) {
                f[i] = 0;
                for (int j = 0; j < i; j++)
                f[i] += f[j];
            }
        }
    cout<<f[n];
}
    