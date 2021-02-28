#include "bits/stdc++.h"
using namespace std;

signed main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (c == d) puts("0");
    else if (c < d) {
        int ans = (d - c - 1) * (a + 2 * b);
        ans += 2 * b;
        cout << ans << "\n";
    }
    else {
        int ans = (c - d) * (a + 2 * b) + a;
        cout << ans << "\n";
    }
}
