#include "bits/stdc++.h"
using namespace std;

struct pt {
    long long x, y;
    pt() {}
    pt(long long _x, long long _y) : x(_x), y(_y) {}
    pt operator-(const pt& p) const { return pt(x - p.x, y - p.y); }
    long long cross(const pt& p) const { return x * p.y - y * p.x; }
    long long cross(const pt& a, const pt& b) const { return (a - *this).cross(b - *this); }
};

int sgn(const long long& x) { return x >= 0 ? x ? 1 : 0 : -1; }

bool inter1(long long a, long long b, long long c, long long d) {
    if (a > b)
        swap(a, b);
    if (c > d)
        swap(c, d);
    return max(a, c) <= min(b, d);
}

bool check_inter(const pt& a, const pt& b, const pt& c, const pt& d) {
    if (c.cross(a, d) == 0 && c.cross(b, d) == 0)
        return inter1(a.x, b.x, c.x, d.x) && inter1(a.y, b.y, c.y, d.y);
    return sgn(a.cross(b, c)) != sgn(a.cross(b, d)) &&
           sgn(c.cross(d, a)) != sgn(c.cross(d, b));
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int dp[20][20];
        memset(dp, 0, sizeof dp);
        vector<pt> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i].x >> a[i].y >> b[i].x >> b[i].y;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (check_inter(a[i], b[i], a[j], b[j])) {
                    dp[i][j] = dp[j][i] = 1;
                }
            }
            dp[i][i] = 1;
        }
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (dp[i][k] && dp[k][j]) {
                        dp[i][j] = 1;
                    }
                }
            }
        }
        int x, y;
        while (cin >> x >> y) {
            if (x == 0 && y == 0) break;
            if (!dp[x][y]) cout << "NOT ";
            puts("CONNECTED");
        }
        if (t) puts("");
    }
}
