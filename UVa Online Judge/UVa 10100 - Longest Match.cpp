#include "bits/stdc++.h"
using namespace std;

signed main()
{
    function<vector<string>(string)> tokenizer = [&] (string a) {
        for (int i = 0; i < a.size(); i++) {
            if (!isalnum(a[i])) a[i] = ' ';
        }
        stringstream tk(a);
        vector<string> ret;
        string h;
        while (tk >> h) {
            ret.push_back(h);
        }
        return ret;
    };
    //freopen("input.txt", "r", stdin);
    string in;
    int cs = 1;
    while (getline(cin, in)) {
        string h;
        getline(cin, h);
        vector<string> a, b;
        a = tokenizer(in);
        b = tokenizer(h);
        int n = a.size();
        int m = b.size();
        a.emplace(a.begin(), "");
        b.emplace(b.begin(), "");
        int dp[n + 1][m + 1];
        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i] == b[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        if (dp[n][m] > 0) {
            printf("%2d. Length of longest match: %d\n", cs++, dp[n][m]);
        }
        else {
            printf("%2d. Blank!\n", cs++);
        }
    }
}
