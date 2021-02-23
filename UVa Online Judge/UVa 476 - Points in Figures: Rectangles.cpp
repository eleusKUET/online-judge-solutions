#include "bits/stdc++.h"
using namespace std;
#define eps 1e-9

struct point {
    double x, y;
    point(){};
    point(double a, double b) {
        x = a; y = b;
    };
};

signed main()
{
    //freopen("input.txt", "r", stdin);
    char g;
    vector<point> a, b;
    while (cin >> g) {
        if (g == '*') break;
        point p;
        cin >> p.x >> p.y;
        a.push_back(p);
        cin >> p.x >> p.y;
        b.push_back(p);
    }
    point p;
    int id = 1;
    while(cin >> p.x >> p.y) {
        if (abs(p.x - 9999.9) <= 1e-9 && abs(p.y - 9999.9) <= 1e-9) break;
        bool ok = false;
        for (int i = 0; i < a.size(); i++) {
            if (a[i].x < p.x && p.x < b[i].x && b[i].y < p.y && p.y < a[i].y) {
                printf("Point %d is contained in figure %d\n", id, i + 1);
                ok = true;
            }
        }
        if (!ok) {
            printf("Point %d is not contained in any figure\n", id);
        }
        id++;
    }
}
