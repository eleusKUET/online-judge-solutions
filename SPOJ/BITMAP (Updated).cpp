#include "bits/stdc++.h"
using namespace std;

signed main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> a(n);
        queue<array<int,2>> q;
        int vis[n][m];
        memset(vis, 0, sizeof vis);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            for (int j = 0; j < m; j++) {
                if (a[i][j] == '1') {
                    q.push({i, j});
                    vis[i][j]++;
                }
            }
        }

        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (abs(j) == abs(i)) continue;
                    int x = u[0] + i;
                    int y = u[1] + j;
                    if (x < 0 || y < 0 || x >= n || y >= m || vis[x][y]) continue;
                    q.push({x, y});
                    vis[x][y] = vis[u[0]][u[1]] + 1;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << vis[i][j] - 1;
                if (j + 1 < m) cout << " ";
                else cout << "\n";
            }
        }
    }
}
