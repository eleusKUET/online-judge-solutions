#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        bool a[n + 1];
        memset(a, 0, sizeof a);
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j += i) {
                a[j] = !a[j];
            }
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            cnt += a[i];
        cout << cnt << "\n";
    }
}
