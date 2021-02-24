#include "bits/stdc++.h"
using namespace std;
#define int long long

int mod;
int mul(int a, int b)
{
    return ((a%mod) * (b%mod))%mod;
}

int modpow(int a, int b)
{
    if (b == 0) return 1%mod;
    int u = modpow(a, b / 2);
    u = mul(u, u);
    if (b & 1) u = mul(u, a);
    return u;
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    int b, p, m;
    while (cin >> b >> p >> m) {
        mod = m;
        cout << modpow(b, p) << "\n";
    }
}
