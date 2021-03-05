#include "bits/stdc++.h"
using namespace std;

const int N = 505;
int par[N];
int sz[N];
int x[N];
int y[N];
int s, p;

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
    par[b] = a;
    return true;
}

int divide(int d)
{
    for (int i = 0; i < p; i++) {
        sz[i] = 1; par[i] = i;
    }
    int com = p;
    for (int i = 0; i < p; i++) {
        for (int j = i + 1; j < p; j++) {
            int dist = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
            if (dist <= d) {
                com -= Union(i, j);
            }
        }
    }
    return com;
}

void solve()
{
    cin >> s >> p;
    for (int i = 0; i < p; i++) {
        cin >> x[i] >> y[i];
        par[i] = i;
        sz[i] = 1;
    }
    int lo = 1;
    int hi = 1e9;
    int ac = 0;
    int com = -1;
    while (lo <= hi) {
        int mid = lo + hi >> 1;
        if (divide(mid) <= s) {
            hi = mid - 1;
            ac = mid;
            com = divide(mid);
        }
        else {
            lo = mid + 1;
        }
    }
    //debug(ac, com);
    cout << setprecision(2) << fixed << sqrt(ac) << "\n";
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}
