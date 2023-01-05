// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(...)
#endif

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T> using oset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template <class K,class V> using omap = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define f first
#define s second
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define vpi vector<pair<int,int>>
#define ll long long
#define pll pair<long long,long long>
#define vpl vector<pair<long long,long long>>
#define vll vector<long long>
#define lb lower_bound
#define ub upper_bound
#define Checkbit(a,i) (((a)>>(i))&1)
#define Setbit(a,i) ((a)^=1LL<<(i))

const int mod = 1e9 + 7;

const int N = 1e5;

void solve()
{
    int n;
    int cs = 1;
    while (scanf("%d", &n)) {
        if (n == 0) break;
        if (cs > 1) {
            puts("");
        }
        int l, c;
        scanf("%d%d", &l, &c);

        vi a(n + 5);

        for (int i= 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }

        auto dissat = [&] (int val) {
            if (val == 0) return 0;
            if (val <= 10) return -c;
            return (val - 10) * (val - 10);
        };

        vi dp(n + 5, mod);
        vi dq(n + 5, mod);
        int valid[n + 5][n + 5];

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
               valid[i][j] = mod;
            }
        }

        for (int i = 1; i <= n; i++) {
            int dis = 0;
            int tm = 0;
            for (int j = i; j <= n; j++) {
                tm += a[j];
                if (tm > l) break;
                dis = dissat(l - tm);
                valid[i][j] = dis;
            }
        }
        dp[0] = 0;
        dq[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (valid[j + 1][i] >= mod) continue;
                if (dp[i] > dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    dq[i] = dq[j] + valid[j + 1][i];
                }
                else if (dp[i] == dp[j] + 1) {
                    dq[i] = min(dq[i], dq[j] + valid[j + 1][i]);
                }
            }
        }

        printf("Case %d:\n", cs++);
        printf("Minimum number of lectures: %d\n", dp[n]);
        printf("Total dissatisfaction index: %d\n", dq[n]);
    }
}

signed main()
{
    // freopen("input.txt", "r", stdin);
    int t = 1;
    // cin >> t;
    int cs = 1;
    while (t--) {
        //cout << "Case " << cs++ << ":" << " ";
        solve();
    }
}
