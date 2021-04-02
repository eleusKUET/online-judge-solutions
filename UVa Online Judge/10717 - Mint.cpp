#include "bits/stdc++.h"
using namespace std;
#define int long long

int __lcm(int a, int b)
{
    return a * b / __gcd(a, b);
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    int n, t;
    while (cin >> n >> t) {
        if (!n && !t) break;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < t; i++) {
            int h;
            cin >> h;
            int mn = 0;
            int mx = INT_MAX;
            for (int p = 0; p < n; p++) {
                for (int q = p + 1; q < n; q++) {
                    for (int r = q + 1; r < n; r++) {
                        for (int s = r + 1; s < n; s++) {
                            int lcm = __lcm(a[p], a[q]);
                            lcm = __lcm(lcm, a[r]);
                            lcm = __lcm(lcm, a[s]);
                            mn = max(mn, (h / lcm) * lcm);
                            mx = min(mx, ((h + lcm - 1) / lcm) * lcm);
                        }
                    }
                }
            }
            cout << mn << " " << mx << "\n";
        }
    }
}
