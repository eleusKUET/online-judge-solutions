#include "bits/stdc++.h"
using namespace std;

signed main()
{
    //freopen("input.txt", "r", stdin);
    int cs = 1;
    int v, e;
    while (cin >> v >> e) {
        if (!v && !e) break;
        vector<int> tm(v);
        for (int i = 0; i < v; i++) {
            cin >> tm[i];
        }
        vector<int> g[v], h[v];
        for (int i = 0; i < e; i++) {
            int x, y; cin >> x >> y; x--; y--;
            g[x].push_back(y);
            h[y].push_back(x);
        }
        vector<int> used(v);
        function<int(int)> dfs = [&](int u) {
            if (used[u]) return 0;
            used[u] = 1;
            int sum = tm[u];
            for (auto it : g[u]) {
                sum += dfs(it);
            }
            return sum;
        };
        function<int(int)> dfs2 = [&](int u) {
            if (used[u]) return 0;
            used[u] = 1;
            int sum = tm[u];
            for (auto it : h[u]) {
                sum += dfs2(it);
            }
            return sum;
        };
        int sum = accumulate(tm.begin(), tm.end(), 0);
        int q;
        cin >> q;
        printf("Case #%d:\n", cs++);
        while (q-- ){
            int h; cin >> h; h--;
            fill(used.begin(), used.end(), 0);
            int mn = dfs(h) - tm[h];
            fill(used.begin(), used.end(), 0);
            int mx = sum - dfs2(h);
            cout << mx - mn << "\n";
        }
        cout << "\n";
    }
}
