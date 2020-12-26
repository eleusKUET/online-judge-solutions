#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main()
{
    int a, b;
    while (cin >> a >> b) {
        if (a == 0 && b == 0) break;
        cout << (b / 5) - (a / 5) + 1 << "\n";
    }
}
