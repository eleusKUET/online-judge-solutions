#include "bits/stdc++.h"
using namespace std;

struct point2d {
    long long x, y;
    point2d() {}
    point2d(long long a, long long b) {
        x = a; y = b;
    }
    point2d operator-(const point2d &a) const {
        return point2d(x - a.x, y - a.y);
    }
    long long cross(const point2d &a) const {
        return this->x * a.y - this->y * a.x;
    }
    long long cross(const point2d &a, const point2d &b) const {
        return (a - *this).cross(b - *this);
    }
};
int sign(const long long x) {
    if (x >= 0) return (x ? 1 : 0);
    return -1;
}
bool inter1(long long a, long long b, long long c, long long d) {
    if (a > b) swap(a, b);
    if (c > d) swap(c, d);
    return max(a, c) <= min(b, d);
}
bool Intersect(const point2d &a, const point2d &b, const point2d &c, const point2d &d) {
    if (c.cross(a, b) == 0 && d.cross(a, b) == 0) {
        return inter1(a.x, b.x, c.x, d.x) && inter1(a.y, b.y, c.y, d.y);
    }
    return (sign(c.cross(a, b)) != sign(d.cross(a, b)) && sign(a.cross(c, d)) != sign(b.cross(c, d)));
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<point2d> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].x >> a[i].y >> b[i].x >> b[i].y;
        }
        int par[n], sz[n];
        for (int i = 0; i < n; i++) {
            par[i] = i; sz[i] = 1;
        }
        function<int(int)> Find = [&] (int u) {
            if (par[u] == u) return u;
            return par[u] = Find(par[u]);
        };
        function<void(int,int)> Union = [&] (int u, int v) {
            int a = Find(u);
            int b = Find(v);
            if (a == b) return;
            if (sz[a] < sz[b]) swap(a, b);
            par[b] = a;
            sz[a] += sz[b];
        };
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (Intersect(a[i], b[i], a[j], b[j])) {
                    Union(i, j);
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += (sz[i] == 1 && par[i] == i);
        }
        cout << cnt << "\n";
    }
}
