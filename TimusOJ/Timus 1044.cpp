#include "bits/stdc++.h"
using namespace std;

signed main()
{
    //freopen("input.txt", "r", stdin);
    int n; cin >> n;
    int N = 1;
    n /= 2;
    while(n--) {
        N *= 10;
    }
    //debug(N);
    vector<int> cnt(50);
    for (int i = 0; i < N; i++) {
        int sum = 0;
        int h = i;
        while (h > 0) {
            sum += h%10; h /= 10;
        }
        cnt[sum]++;
    }
    int ans = 0;
    for (int i = 0; i < 50; i++) {
        //debug(cnt[i], i);
        ans += cnt[i] * cnt[i];
    }
    cout << ans << "\n";
}
