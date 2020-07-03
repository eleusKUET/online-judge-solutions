#include<bits/stdc++.h>
using namespace std;

const int N = 25;
char g[N][N];
int vis[N][N];

char l;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int n, m;
bool isvalid(int r, int c)
{
    return (r >= 0 && r < m && g[r][c] == l);
}

int fix(int c)
{
    if (c < 0) return n - 1;
    if (c >= n) return 0;
    return c;
}
int dfs(int r, int c)
{
    vis[r][c] = 1;
    for (int i = 0; i < 4; i++) {
        int dr = r + dx[i];
        int dc = fix(c + dy[i]);
        if (isvalid(dr, dc) && !vis[dr][dc]) {
            dfs(dr, dc);
            vis[r][c] += vis[dr][dc];
        }
    }
    return vis[r][c];
}

int main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    while (cin >> m >> n) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> g[i][j];
            }
        }
        int x, y;
        cin >> x >> y;
        l = g[x][y];
        dfs(x, y);
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][j] == l && !vis[i][j]) {
                    int cur = dfs(i, j);
                    res = max(res, cur);
                }
            }
        }
        cout << res << "\n";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vis[i][j] = g[i][j] = 0;
            }
        }
    }
}
