#include "bits/stdc++.h"
using namespace std;

struct circle {
    double X, Y, R; circle() {}
    circle(double x, double y, double r) {
        X = x; Y = y; R = r;
    }
    const double eps = 1e-6;
    bool overlap(circle a) {
        double mi = abs(this->R - a.R);
        double pl = this->R + a.R;
        double d = (this->X - a.X) * (this->X - a.X) + (this->Y - a.Y) * (this->Y - a.Y);
        return (mi * mi - eps <= d && pl * pl + eps >= d);
    }
};

int par[105];
int sz[105];

int Find(int u)
{
    if (u == par[u]) return u;
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

signed main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    while (cin >> n) {
        if (n == -1) break;
        circle a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i].X >> a[i].Y >> a[i].R;
            par[i] = i;
            sz[i] = 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[i].overlap(a[j])) {
                    Union(i, j);
                }
            }
        }
        int mx = 0;
        for (int i = 0; i < n; i++) {
            mx = max(mx, sz[i]);
        }
        cout << "The largest component contains " << mx << " ring";
        if (mx == 1) cout << ".\n";
        else cout << "s.\n";
    }
}
