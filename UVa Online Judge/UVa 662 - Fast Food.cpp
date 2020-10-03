#include "bits/stdc++.h"
using namespace std;
#define int long long

const int INF = (int)1e15;
struct state {
    int from, to, mid, cnt; state() {}
    state(int a, int b, int c, int d) {
        from = a; to = b; mid = c; cnt = d;
    }
};

signed main()
{
    //freopen("input.txt", "r", stdin);
    int cs = 1;
    int N, K;
    while (cin >> N >> K) {
        if (N == 0 && K == 0) break;

        int a[N + 1];
        for (int i = 1; i <= N; i++) {
            cin >> a[i];
        }

        int pre[N + 1];
        pre[0] = 0;
        for (int i = 1; i <= N; i++) {
            pre[i] = pre[i - 1] + a[i];
        }

        auto sum = [&] (int i, int j) {
            return pre[j] - pre[i - 1];
        };
        auto cost = [&] (int i, int j) {
            int mid = i + j >> 1;
            return a[mid] * (mid - i) - sum(i, mid - 1) + sum(mid + 1, j) - a[mid] * (j - mid);
        };

        int dp[N + 1][K + 1];
        state path[N + 1][K + 1];
        for (int i = 0; i <= N; i++)
            for (int j = 0; j <= K; j++)
                dp[i][j] = INF;

        dp[0][0] = 0;
        path[0][0].mid = -1;

        for (int i = 1; i <= N; i++) {
            for (int j = i; j <= N; j++) {
                for (int k = 1; k <= K; k++) {
                    int ret = dp[i - 1][k - 1] + cost(i, j);
                    if (ret < dp[j][k]) {
                        dp[j][k] = ret;
                        path[j][k].from = i;
                        path[j][k].to = j;
                        path[j][k].mid = i + j >> 1;
                        path[j][k].cnt = k - 1;
                    }
                }
            }
        }

        vector<state> v;
        state root = path[N][K];

        while (root.mid != -1) {
            v.push_back(root);
            root = path[root.from - 1][root.cnt];
        }
        reverse(v.begin(), v.end());
        cout << "Chain " << cs++ << "\n";
        for (int i = 0; i < v.size(); i++) {
            printf("Depot %lld at restaurant %lld serves restaurant", i + 1, v[i].mid);
            if (v[i].from != v[i].to) {
                printf("s %lld to %lld\n", v[i].from, v[i].to);
            }
            else {
                printf(" %lld\n", v[i].from);
            }
        }
        printf("Total distance sum = %lld\n\n", dp[N][K]);
    }
}
