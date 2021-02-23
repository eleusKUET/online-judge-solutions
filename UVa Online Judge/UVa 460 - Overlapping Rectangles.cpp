#include "bits/stdc++.h"
using namespace std;

struct point {
    int y, x; point(){}
    point(int a, int b) {
        x = a; y = b;
    }
};

signed main()
{
    //freopen("input.txt", "r", stdin);
    int t; cin >> t;
    while (t--) {
        point a, b;
        cin >> a.x >> a.y >> b.x >> b.y;
        point c, d;
        cin >> c.x >> c.y >> d.x >> d.y;
        point p = point(max(a.x, c.x), max(a.y, c.y));
        point q = point(min(b.x, d.x), min(d.y, b.y));
        if (p.x >= q.x || p.y >= q.y) {
            puts("No Overlap");
        }
        else {
            cout << p.x << " " << p.y << " " << q.x << " " << q.y << "\n";
        }
        if (t) puts("");
    }
}
