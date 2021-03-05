#include "bits/stdc++.h"
using namespace std;

struct edge {
    int u, v, w;
};

bool comp(edge a, edge b)
{
    return a.w < b.w;
}

const int N = 755;
int x[N];
int y[N];
edge a[N * N];
int par[N];
int sz[N];

int Find(int u)
{
    if (par[u] == u) return u;
    return par[u] = Find(par[u]);
}

void Union(int u, int v)
{
    int a = Find(u);
    int b = Find(v);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    par[b] = a;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        par[i] = i; sz[i] = 1;
    }
    int m;
    cin >> m;
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        cin >> a[i].u >> a[i].v;
        a[i].u--; a[i].v--;
        if (Find(a[i].u) != Find(a[i].v)) {
            Union(a[i].u, a[i].v);
            cnt++;
        }
    }
    if (cnt == n - 1) {
        puts("No new highways need");
        return;
    }
    m = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            a[m].u = i; a[m].v = j;
            a[m].w = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
            m++;
        }
    }

    sort(a, a + m, comp);
    for (int i = 0; i < m; i++) {
        if (Find(a[i].u) == Find(a[i].v)) continue;
        Union(a[i].u, a[i].v);
        cout << a[i].u + 1 << " " << a[i].v + 1 << "\n";
    }
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        solve();
        if (t) puts("");
    }
}
