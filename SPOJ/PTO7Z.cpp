#include<bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 5;
vector<int> g[N];
int maxd;
int far;
 
void dfs(int u, int p, int dep)
{
    for (auto v : g[u]) {
        if (v != p) {
            dfs(v, u, dep + 1);
        }
    }
    if (maxd < dep) {
        maxd = dep;
        far = u;
    }
}
 
signed main()
{
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    int u, v;
    for (int i = 1; i <= n - 1; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1, 0);
    u = far;
    maxd = 0;
    dfs(u, -1, 0);
    cout << maxd << "\n";
}
