#include "bits/stdc++.h"
using namespace std;

signed main()
{
    int t, cs = 1;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        printf("Case %d: ", cs++);
        if (n == 1 || m == 1) {
            cout << max(m, n) << "\n";
        }
        else if (m == 2 || n == 2) {
            int r = (n * m / 8) * 4;
            if ((n * m)%8 < 4) r += (n * m)%8;
            else r += 4;
            cout << r << "\n";
        }
        else {
            cout << (m * n + 1) / 2 << "\n";
        }
    }
}
