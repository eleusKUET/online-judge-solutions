#include "bits/stdc++.h"
using namespace std;

const int maxn = 2e7 + 5;
int cal[maxn];

void pre()
{
    int limit = sqrt(maxn);
    for (int i = 1; i <= limit; i++) {
        for (int j = i; j < maxn; j += i) {
            cal[j] += i;
            if (j / i > limit) cal[j] += j / i;
        }
    }
    //debug(cal[2]);
    for (int i = 3; i < maxn; i++) {
        //debug(cal[i], i);
        cal[i] += cal[i - 1];
    }
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    pre();

    int n;
    while (cin >> n) {
        if (n == 0) break;
        cout << cal[n] << "\n";
    }
}
