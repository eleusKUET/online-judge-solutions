#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    while (cin >> n >> m) {
        if (!n && !m) break;
        vector<int> a;
        for (int i = 1, j = n; i <= m; i++, j--) {
            a.push_back(j);
        }
        for (int i = 2; i <= m; i++) {
            int h = i;
            for (int j = 0; j < a.size(); j++) {
                if (h == 1) break;
                int g = __gcd(a[j], h);
                a[j] /= g; h /= g;
            }
        }
        int prod = 1;
        for (int i = 0; i < a.size(); i++) {
            prod *= a[i];
        }
        printf("%lld things taken %lld at a time is %lld exactly.\n", n, m, prod);
    }
}
