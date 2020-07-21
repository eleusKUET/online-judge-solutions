#include<bits/stdc++.h>
using namespace std;

signed main()
{
    //freopen("input.txt", "r", stdin);
    unordered_map<char,int> sign;
    sign['('] = 1;
    sign['{'] = 2;
    sign['['] = 3;
    sign['<'] = 4;
    sign[')'] = -1;
    sign['}'] = -2;
    sign[']'] = -3;
    sign['>'] = -4;
    int t;
    cin >> t;
    string x; getline(cin, x);
    int cs = 0;
    while (t--) {
        getline(cin, x);
        int n = x.size();
        int dp[n + 1];
        memset(dp, 0, sizeof dp);
        for (int i = n - 1; i >= 0; i--) {
            int now = sign[x[i]];
            if (now < 0) continue;
            if (i + 1 < n && now == -1 * sign[x[i + 1]]) dp[i] = 2 + dp[i + 2];
            else if (i + 1 < n) {
                int nxt = sign[x[dp[i + 1] + i + 1]];
                if (nxt*-1 == now) {
                    dp[i] = dp[i + 1] + 2 + dp[dp[i + 1] + i + 2];
                }
                else dp[i] = 0;
            }
            else dp[i] = 0;
        }
        cout << "Case " << ++cs << ":\n";
        for (int i = 0; i < n; i++)
            cout << dp[i] << "\n";
    }
}
