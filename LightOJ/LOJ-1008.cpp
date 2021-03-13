#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main()
{
    int t, cs = 1; cin >> t;
    while (t--) {
        int n; cin >> n;
        int root = sqrt(n * 1.0);
        if (root * root < n) root++;
        int a = root * root;
        int x, y;
        if (a >= n && a - root + 1 <= n) {
            x = a - n + 1;
            y = root;
        }
        else {
            x = root;
            y = n - (root - 1) * (root - 1);
        }
        if (a%2 == 0) swap(x, y);
        printf("Case %lld: %lld %lld\n", cs++, x, y);
    }
}
