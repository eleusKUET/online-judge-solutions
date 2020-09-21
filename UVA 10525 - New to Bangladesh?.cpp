#include "bits/stdc++.h"
using namespace std;
#define int long long
#define INF INT_MAX

int r[50][50];
int t[50][50];

signed main()
{
    //freopen("input.txt", "r", stdin);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                r[i][j] = (i == j) ? 0 : INF;
                t[i][j] = (i == j) ? 0 : INF;
            }
        }
        while (m--) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            if (t[a][b] > c || (t[a][b] == c && r[a][b] > d)) {
                t[a][b] = t[b][a] = c;
                r[a][b] = r[b][a] = d;
            }
        }
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (t[i][k] != INF && t[k][j] != INF && r[i][k] != INF && r[k][j] != INF) {
                        if (t[i][j] > t[i][k] + t[k][j] || (t[i][j] == t[i][k] + t[k][j] && r[i][j] > r[i][k] + r[k][j])) {
                            t[i][j] = t[i][k] + t[k][j];
                            r[i][j] = r[i][k] + r[k][j];
                        }
                    }
                }
            }
        }
        int q; cin >> q ;
        while (q--) {
            int s, d;
            cin >> s >> d;
            if (r[s][d] != INF && t[s][d] != INF) printf("Distance and time to reach destination is %lld & %lld.\n", r[s][d], t[s][d]);
            else puts("No Path.");
        }
        if (tt) puts("");
    }
}
