#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main()
{
    int n;
    while (cin >> n) {
        if (n == 0) break;
        int lo = 1, hi = 1e6;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (mid * mid <= n) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        if ((lo - 1) * (lo - 1) == n) cout << "yes\n";
        else cout << "no\n";
    }
}
