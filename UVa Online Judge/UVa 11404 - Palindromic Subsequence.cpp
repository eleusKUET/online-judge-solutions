#include "bits/stdc++.h"
using namespace std;
using II = pair<int,string>;

const int N = 1005;
II dp[N][N];
string a;

II solve(int u, int v)
{
    if (u == v) {
        string tmp;
        tmp += a[u];
        return dp[u][v] = {1, tmp};
    }
    if (u > v) return {0, ""};

    int ex = dp[u][v].first;
    if (ex != -1) return dp[u][v];

    if (a[u] == a[v]) {
        II ret = solve(u + 1, v - 1);
        ret.first += 2;
        string tmp;
        tmp += a[u];
        tmp += ret.second;
        tmp += a[v];
        ret.second = tmp;
        return dp[u][v] = ret;
    }
    II p = solve(u, v - 1);
    II q = solve(u + 1, v);
    if (p.first == q.first) return dp[u][v] = (p.second < q.second) ? p : q;
    if (p.first > q.first) return dp[u][v] = p;
    return dp[u][v] = q;
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    while (cin >> a) {
        int n = a.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j].first = -1;
                dp[i][j].second = "";
            }
        }
        II ans = solve(0, n - 1);
        //debug(ans.first);
        cout << ans.second << "\n";
    }
}
