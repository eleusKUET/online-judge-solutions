#include "bits/stdc++.h"
using namespace std;

signed main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    int cs = 0;
    while (cin >> n) {
        int g[205][205];
        memset(g, 0, sizeof g);
        int mx = 0;
        for (int i = 0; i < n; i++) {
            int u, v;
            cin >> u >> v;
            g[u][v] = 1;
            mx = max(mx, max(u, v));
        }
        n = mx;
        for (int k = 0; k <= n; k++) {
            for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= n; j++) {
                    if (g[i][k] && g[k][j]) {
                        g[i][j] += g[i][k] * g[k][j];
                    }
                }
            }
        }
        for (int k = 0; k <= n; k++) {
            if (g[k][k]) {
                for (int i = 0; i <= n; i++) {
                    for (int j = 0; j <= n; j++) {
                        if (g[i][k] && g[k][j]) {
                            g[i][j] = -1;
                        }
                    }
                }
            }
        }
        cout << "matrix for city " << cs++ << "\n";
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (j > 0) cout << " ";
                if (i == j && g[i][j] > 0) cout << -1;
                else cout << g[i][j];
            }
            cout << "\n";
        }
    }
}
