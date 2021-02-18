#include "bits/stdc++.h"
using namespace std;

signed main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, c;
    while (cin >> n >> m >> c) {
        if (!n && !m && !c) break;
        int cnt = 0;
        for (int i = 8; i <= m; i++) {
            if (c) {
                if ((n + m)%2 == (i + 1)%2) {
                    int h = (n + 1) / 2 - 1;
                    if (h - 3 > 0) cnt += h - 3;
                }
                else {
                    int h = n / 2;
                    if (h - 3 > 0) cnt += h - 3;
                }
            }
            else {
                if ((n + m)%2 != (i + 1)%2) {
                    int h = (n + 1) / 2 - 1;
                    if (h - 3 > 0) cnt += h - 3;
                }
                else {
                    int h = n / 2;
                    if (h - 3 > 0) cnt += h - 3;
                }
            }
        }
        cout << cnt << "\n";
    }
}
