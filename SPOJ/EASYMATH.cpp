//SPOJ EASYMATH
//Author: Eleus Ahammad
//CSE, KUET

#include<bits/stdc++.h>
using namespace std;
#define int int64_t

int n, m, a, d;

int __lcm(int a, int b)
{
    return a * b / __gcd(a, b);
}

int solve(int x)
{
    int help[5];
    for (int i = 0; i < 5; i++)
      help[i] = a + i * d;
    int ans = 0;
    for (int i = 1; i < (1<<5); i++) {
        int lcm = 1;
        for (int j = 0; j < 5; j++) {
            if (i & (1<<j)) {
                lcm = __lcm(help[j], lcm);
            }
        }
        if (__builtin_popcount(i)%2) ans += x / lcm;
        else ans -= x / lcm;
    }
    return x - ans;
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m >> a >> d;
        cout << solve(m) - solve(n - 1) << "\n";
    }
}
