#include<bits/stdc++.h>
using namespace std;
#define eps 1e-6
//#include "debugger.cpp"

struct segment {
    double A, B, X, Y; segment(double a, double b, double c, double d) {
        A = a; B = b; X = c; Y = d;
    }
    bool intersect(segment a) {
        double p1 = this->A - this->X;
        double p2 = a.A - a.X;
        double p3 = a.A - this->A;
        double q1 = this->B - this->Y;
        double q2 = a.B - a.Y;
        double q3 = a.B - this->B;
        double t1 = (-p2 * q3 + p3 * q2) / (-p1 * q2 + q1 * p2);
        double t2 = (q1 * p3 - p1 * q3) / (-p1 * q2 + q1 * p2);
        return !(t1 < 0.0 - eps || t1 > 1 + eps || t2 < 0.0 - eps || t2 > 1.0 + eps);
    }
};

signed main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    int f = 0;
    while (t--) {
        int n;
        cin >> n;
        double x1, y1, x2, y2;
        vector<segment> v;
        for (int i = 1; i <= n; i++) {
            cin >> x1 >> y1 >> x2 >> y2;
            v.push_back(segment(x1, y1, x2, y2));
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = i + 1; j < n; j++) {
                if (v[i].intersect(v[j])) cnt += 2;
            }
            cnt++;
            ans += cnt;
        }
        if (f++) cout << "\n";
        cout << ans << "\n";
    }
}
