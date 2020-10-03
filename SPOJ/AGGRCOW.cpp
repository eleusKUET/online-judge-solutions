#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, c;
        cin >> n >> c;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        int lo = a[0], hi = a[n - 1];
        int ans = 0;
        while (lo <= hi) {
            int mid = lo + hi >> 1;
            int cnt = 1;
            int prev = a[0];
            for (int i = 1; i < n; i++) {
                if (a[i] - prev >= mid) {
                    cnt++;
                    prev = a[i];
                }
            }
            if (cnt >= c) {
                ans = mid;
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        cout << ans << "\n";
    }
}
