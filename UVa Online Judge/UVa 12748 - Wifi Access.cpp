#include "bits/stdc++.h"
using namespace std;

signed main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    int cs = 1;
    while (t--) {
        int n, y;
        cin >> n >> y;
        struct circle {
            int x, y, rad; circle () {}
            circle(int _x, int _y) {
                x = _x; y = _y;
            }
            bool Into(int a, int b) {
                int norm = (x - a) * (x - a) + (y - b) * (y - b);
                return norm <= rad * rad;
            }
        };
        vector<circle> v(n);
        for (int i = 0; i < n ; i++) {
            cin >> v[i].x >> v[i].y >> v[i].rad;
        }
        printf("Case %d:\n", cs++);
        for (int i = 0; i < y; i++) {
            int a, b; cin >> a >> b;
            bool ok = false;
            for (circle it : v) {
                ok |= it.Into(a, b);
            }
            ok = !ok;
            cout << (ok ? "No" : "Yes") << "\n";
        }
    }
}
