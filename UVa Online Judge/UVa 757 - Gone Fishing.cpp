#include "bits/stdc++.h"
using namespace std;

const int N = 27;
int f[N], t[N], d[N];
int dp[200][200][N];
int h, n;
int path[N];

int solve(int it, int rem, int taken)
{
    if (it == n) return 0;
    int &ret = dp[rem][taken][it];
    if (ret != -1) return ret;
    int option1 = 0, option2 = 0;
    if (rem > 0) {
        int tmp = max(f[it] - d[it] * taken, 0);
        option1 = tmp + solve(it, rem - 1, taken + 1);
    }
    if (rem - t[it] >= 0) {
        option2 = solve(it + 1, rem - t[it], 0);
    }
    return ret = max(option1, option2);
}

void print(int it, int rem, int taken)
{
    if (it == n) return;
    int option1, option2;
    option1 = option2 = -1;
    if (rem > 0) {
        int tmp = f[it] - d[it] * taken;
        option1 = max(tmp, 0) + solve(it, rem - 1, taken + 1);
    }
    if (rem >= t[it]) {
        option2 = solve(it + 1, rem - t[it], 0);
    }
    if (solve(it, rem, taken) == option1) {
        path[it]++;
        print(it, rem - 1, taken + 1);
    }
    else if (option2 != -1) {
        print(it + 1, rem - t[it], 0);
    }
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    int line = 0;
    while (cin >> n) {
        if (n == 0) break;
        cin >> h;
        h *= 12;
        memset(t, 0, sizeof t);
        memset(dp, -1, sizeof dp);
        memset(path, 0, sizeof path);
        for (int i = 0; i < n; i++) {
            cin >> f[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> d[i];
        }
        for (int i = 0; i < n - 1; i++) {
            cin >> t[i];
        }
        if (line++) puts("");
        int ans = solve(0, h, 0);
        print(0, h, 0);
        for (int i = 0; i < n; i++) {
            if (i > 0) cout << ", ";
            cout << path[i] * 5;
        }
        cout << "\n";
        cout << "Number of fish expected: " << ans << "\n";
    }
}
