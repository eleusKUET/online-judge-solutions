#include "bits/stdc++.h"
using namespace std;

const int N = 2005;
int par[N];
int sz[N];

int Find(int u)
{
    if (par[u] == u) return u;
    return par[u] = Find(par[u]);
}

bool Union(int u, int v)
{
    int a = Find(u);
    int b = Find(v);
    if (a == b) return false;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    par[b] = a; return true;
}

struct edge{
    string u, v; int w;
};

signed main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i <= n; i++) {
            par[i] = i; sz[i] = 1;
        }
        map<string,int> id;
        int cnt = 1;
        edge a[m];
        for (int i = 0; i < m; i++) {
            cin >> a[i].u >> a[i].v >> a[i].w;
            if (!id[a[i].u]) id[a[i].u] = cnt++;
            if (!id[a[i].v]) id[a[i].v] = cnt++;
        }
        auto comp = [](edge a, edge b) {
            return a.w < b.w;
        };
        sort(a, a + m, comp);
        int ans = 0;
        for (int i = 0; i < m; i++) {
            if (Union(id[a[i].u], id[a[i].v])) {
                ans += a[i].w;
            }
        }
        cout << ans << "\n";
        if (t) puts("");
    }
}
