#include "bits/stdc++.h"
using namespace std;

signed main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int s, m;
    while (cin >> s >> m) {
        if (__gcd(s, m) == 1) {
            printf("%10d%10d    Good Choice\n", s, m);
        }
        else {
            printf("%10d%10d    Bad Choice\n", s, m);
        }
        puts("");
    }
}
