#include "bits/stdc++.h"
using namespace std;

const int N = 1005;
int dp[N][N];
string a;
int odd;
string path;

int solve(int u, int v)
{
    if (u >= v) return 0;
    int &ret = dp[u][v];
    if (ret != -1) return ret;
    if (a[u] == a[v]) ret = solve(u + 1, v - 1);
    else ret = min(solve(u + 1, v) + 1, solve(u, v - 1) + 1);
    return ret;
}

void solve2(int u, int v)
{
    if (u == v) odd = 1, path += a[u];
    if (u >= v) return;
    if (a[u] == a[v]) {
        path += a[u];
        solve2(u + 1, v - 1);
    }
    else if (solve(u, v) == 1 + solve(u + 1, v)) {
        path += a[u];
        solve2(u + 1, v);
    }
    else {
        path += a[v];
        solve2(u, v - 1);
    }
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    while (cin >> a) {
        int n = a.size();
        memset(dp, -1, sizeof dp);
        odd = 0; path = "";
        int ans = solve(0, n - 1);
        solve2(0, n - 1);
        cout << ans << " " << path;
        for (int i = (int)path.size() - 1 - odd; i >= 0; i--) {
            cout << path[i];
        }
        cout << "\n";
    }
}
