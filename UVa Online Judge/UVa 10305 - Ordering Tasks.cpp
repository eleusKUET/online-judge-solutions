#include "bits/stdc++.h"
using namespace std;

signed main()
{
    int n, k;
    while (cin >> n >> k) {
        if (n == 0 && k == 0) break;
        vector<int> g[n + 1];
        for (int i = 1; i <= k; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
        }
        vector<int> fin;
        vector<int> vis(n + 1);
        function<void(int)> dfs = [&](int u) {
            vis[u]++;
            for (auto v : g[u]) {
                if (vis[v]) continue;
                dfs(v);
            }
            fin.push_back(u);
        };
        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            dfs(i);
        }
        reverse(fin.begin(), fin.end());
        for (int i = 0; i < n; i++) {
            cout << fin[i];
            if (i + 1 < n) cout << " ";
            else cout << "\n";
        }
    }
}
