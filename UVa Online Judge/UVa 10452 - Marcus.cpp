#include "bits/stdc++.h"
using namespace std;
#define ii pair<int,int>
#define x first
#define y second

int n, m;
char g[10][10];
int vis[10][10];
vector<ii> path;

bool valid(int r, int c)
{
    if (r < 0 || c < 0 || r >= m || c >= n) return false;
    return (g[r][c] == 'I' || g[r][c] == 'A' || g[r][c] == 'O' || g[r][c] == 'H' || g[r][c] == 'V' || g[r][c] == 'E' || g[r][c] == '@' || g[r][c] == '#');
}

void dfs(int r, int c)
{
    vis[r][c]++;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (abs(i) == abs(j)) continue;
            int x = r + i;
            int y = c + j;
            if (valid(x,  y) && !vis[x][y]) {
                dfs(x, y);
            }
        }
    }
    path.push_back({r, c});
}

void solve()
{
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        cin >> g[i];
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            vis[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        if (g[m - 1][i] == '@') {
            dfs(m - 1, i);
            break;
        }
    }
    //for (int i = 0; i < path.size(); i++) {
      //  debug(path[i].x, path[i].y);
    //}
    reverse(path.begin(), path.end());
    vector<string> cmd;
    for (int i = 1; i < path.size(); i++) {
        if (path[i - 1].x == path[i].x) {
            if (path[i - 1].y < path[i].y) cmd.push_back("right");
            else cmd.push_back("left");
        }
        else cmd.push_back("forth");
    }
    for (int i = 0; i < cmd.size(); i++) {
        if (i > 0) cout << " ";
        cout << cmd[i];
    }
    cout << "\n";
    path.clear();
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
