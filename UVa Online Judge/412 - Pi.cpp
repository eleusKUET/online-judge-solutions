#include "bits/stdc++.h"
using namespace std;

signed main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    while (cin >> n) {
        if (n == 0) break;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int p = 0;
        for (int i = 0; i  < n; i++) {
            for (int j = i + 1; j < n; j++) {
                p += (__gcd(a[i], a[j]) == 1);
            }
        }
        if (!p) {
            puts("No estimate for this data set.");a
        }
        else {
            n = n * (n - 1) / 2;
            double r = sqrt(6.0 * n / p);
            cout << setprecision(6) << fixed << r << "\n";
        }
    }
}
