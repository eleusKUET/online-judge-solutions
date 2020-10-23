#include "bits/stdc++.h"
using namespace std;

signed main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    int cs = 1;
    while (cin >> n) {
        if (n == 0) break;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
        }

        function<int(int,int)> dist = [&] (int i, int j) {
            return (a[i] - a[j]) * (a[i] - a[j]) + (b[i] - b[j]) * (b[i] - b[j]);
        };

        int dp[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = dist(i, j);
            }
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dp[i][j] = min(dp[i][j], max(dp[i][k], dp[k][j]));
                }
            }
        }
        cout << "Scenario #" << cs++ << "\n";
        cout << setprecision(3) << fixed << "Frog Distance = " << sqrt(dp[0][1] * 1.00) << "\n\n";
    }
}
