#include "bits/stdc++.h"
using namespace std;
#define ii pair<int,int>
#define x first
#define y second

ii translate(ii a, ii b)
{
    return {a.x - b.x, a.y - b.y};
}

bool positive(int a)
{
    return (a > 0);
}
bool negative(int a)
{
    return a < 0;
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    while (cin >> n) {
        if (n == 0) break;
        vector<ii> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].x >> a[i].y;
        }
        ii center = a[n / 2];
        for (int i = 0; i < n; i++) {
            a[i] = translate(a[i], center);
        }
        int p = 0;
        int q = 0;
        for (int i = 0; i < n; i++) {
            if (positive(a[i].x) && positive(a[i].y) || negative(a[i].x) && negative(a[i].y)) p++;
            if (negative(a[i].x) && positive(a[i].y) || positive(a[i].x) && negative(a[i].y)) q++;
        }
        cout << p << " " << q << "\n";
    }
}
