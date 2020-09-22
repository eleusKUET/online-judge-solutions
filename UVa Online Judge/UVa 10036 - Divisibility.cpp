#include<bits/stdc++.h>
using namespace std;

signed main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int dp[2][k];
        memset(dp, 0, sizeof dp);
        dp[1][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                dp[0][j] = dp[1][j];
                dp[1][j] = 0;
            }
            for (int j = 0; j < k; j++) {
                int r;
                if (dp[0][j]) {
                    r = j + a[i];
                    r = (r%k + k)%k;
                    dp[1][r] = 1;
                    r = j - a[i];
                    r = (r%k + k)%k;
                    dp[1][r] = 1;
                }
            }
        }
        if (dp[1][0]) {
            puts("Divisible");
        }
        else {
            puts("Not divisible");
        }
    }
}
