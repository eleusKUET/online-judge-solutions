#include "bits/stdc++.h"
using namespace std;

const int N = 2e5 + 5;
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
    int f; cin >> f;
    for (int i = 1; i <= 2 * f; i++) {
        par[i] = i; sz[i] = 1;
    }
    map<string,int> id;
    int cnt = 1;
    for (int i = 1; i <= f; i++) {
        string a, b; cin >> a >> b;
        if (!id[a]) id[a] = cnt++;
        if (!id[b]) id[b] = cnt++;
        Union(id[a], id[b]);
        cout << sz[Find(id[a])] << "\n";
    }
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
