#include "bits/stdc++.h"
using namespace std;

void solve()
{
    int n; cin >> n;
    int h = n;
    if (n == 0) {
        cout << 10 << "\n";
        return;
    }
    if (n <= 9) {
        cout << n << "\n";
        return;
    }
    vector<int> num;
    for (int i = 9; i >= 2; i--) {
        while (n%i == 0) {
            num.push_back(i); n /= i;
        }
    }
    if (n > 9) {
        puts("-1");
        return;
    }
    if (n > 1)num.push_back(n);
    sort(num.begin(), num.end());
    for (int i = 0; i < num.size(); i++) {
        cout << num[i];
    }
    cout << "\n";
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    int t = 1; //cin >> t;
    while (t--)
        solve();
}
