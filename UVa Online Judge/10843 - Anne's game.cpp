#include "bits/stdc++.h"
using namespace std;
#define int long long

const int mod = 2000000011;
int modpow(int a, int b, int m)
{
    if (b == 0) return 1%m;
    int u = modpow(a, b / 2, m);
    u = (u * u)%m;
    if (b & 1) u = (u * a)%m;
    return u;
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    int t, cs = 1;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << "Case #" << cs++ << ": " << modpow(n, n - 2, mod) << "\n";
    }
}
