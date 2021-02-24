#include "bits/stdc++.h"
using namespace std;
#define eps 1e-9

struct point {
    double x, y;
    point(){}
    point(double a, double b) {
        x = a; y = b;
    }
};

bool same(point a, point b)
{
    return (abs(a.x - b.x) <= eps && abs(a.y - b.y) <= eps);
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    point a[4];
    while (cin >> a[0].x >> a[0].y >> a[1].x >> a[1].y >> a[2].x >> a[2].y >> a[3].x >> a[3].y) {
        bool ok = false;
        for (int i = 0; i < 4 && !ok; i++) {
            for (int j = i + 1; j < 4 && !ok; j++) {
                if (same(a[i], a[j])) {
                    double x = 0.0,y = 0.0;
                    for (int k = 0; k < 4; k++) {
                        if (k == i || k == j) continue;
                        x += a[k].x;
                        y += a[k].y;
                    }
                    cout << setprecision(3) << fixed << x - a[i].x << " " << y - a[i].y << "\n";
                    ok = true;
                }
            }
        }
    }
}
