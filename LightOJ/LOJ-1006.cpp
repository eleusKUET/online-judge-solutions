#include "bits/stdc++.h"
using namespace std;
#define int long long

const int mod = 10000007;

int add(int a, int b)
{
    return ((a%mod) + (b%mod))%mod;
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    vector<int> a(10005);
    int t, cs = 1; cin >> t;
    while (t--) {
        for (int i = 0; i < 6; i++) {
            cin >> a[i];
        }
        int n; cin >> n;
        for (int i = 6; i <= n; i++) {
            a[i] = 0;
            for (int j = 1; j <= 6; j++) {
                a[i] = add(a[i], a[i - j]);
            }
        }
        cout << "Case " << cs++ << ": ";
        cout << a[n]%mod << "\n";
    }
}
