#include "bits/stdc++.h"
using namespace std;

signed main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    while (true) {
        if (a >= c) break;
        a += b;
        if (a >= c) {
            a = c;
            break;
        }
        c -= d;
    }
    cout << a << "\n";
}
