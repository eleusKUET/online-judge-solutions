#include "bits/stdc++.h"
using namespace std;

char g[105][105];
int vis[105][105];
int n;
bool ok;

void dfs(int r, int c)
{
    vis[r][c]++;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (abs(i) == abs(j)) continue;
            int x = r + i;
            int y = c + j;
            if (x < 0 || y < 0 || x >= n || y >= n || vis[x][y] || g[x][y] == '.') continue;
            dfs(x, y);
        }
    }
    if (g[r][c] == 'x') ok = true;
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    int cs = 1;
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> g[i][j];
                vis[i][j] = 0;
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && g[i][j] != '.') {
                    ok = 0;
                    dfs(i, j);
                    cnt += ok;
                }
            }
        }
        printf("Case %d: %d\n", cs++, cnt);
    }
}
