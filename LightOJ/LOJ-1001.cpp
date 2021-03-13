#include "bits/stdc++.h"
using namespace std;

signed main()
{
    int t;
    cin >> t;
    while (t--) {
        int a;
        cin >> a;
        if (a > 10) cout << 10 << " " << a - 10 << "\n";
        else cout << 0 << " " << a << "\n";
    }
}
