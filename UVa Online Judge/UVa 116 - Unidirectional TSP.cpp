#include "bits/stdc++.h"
using namespace std;
#define int long long
#define INF (int)1e18

signed main()
{
    //freopen("input.txt", "r", stdin);
    int r, c;
    while (cin >> r >> c) {
        int a[r][c];
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                cin >> a[i][j];

        int dp[r][c];
        int path[r][c];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (j == c - 1) {
                    dp[i][j] = a[i][j];
                    path[i][j] = i;
                }
                else {
                    dp[i][j] = INF;
                    path[i][j] = INF;
                }
            }
        }

        auto form = [&] (int id) {
            if (id < 0) return r - 1;
            if (id == r) return 0LL;
            return id;
        };

        for (int j = c - 2; j >= 0; j--) {
            for (int i = 0; i < r; i++) {
                for (int k = -1; k <= 1; k++) {
                    int id = form(i + k);
                    if (dp[id][j + 1] + a[i][j] < dp[i][j] || (dp[id][j + 1] + a[i][j] == dp[i][j] && id < path[i][j])) {
                        dp[i][j] = dp[id][j + 1] + a[i][j];
                        path[i][j] = id;
                    }
                }
            }
        }
        int mn = INF;
        int start;
        for (int i = 0; i < r; i++) {
            if (dp[i][0] < mn) {
                mn = dp[i][0];
                start = i;
            }
        }

        for (int i = 0; i < c; i++) {
            if (i > 0) cout << " ";
            cout << start + 1;
            start = path[start][i];
        }
        cout << "\n" << mn << "\n";
    }
}
