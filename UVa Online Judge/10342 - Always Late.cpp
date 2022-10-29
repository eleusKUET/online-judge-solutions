// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <sstream>
#include <numeric>

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

const int mod = 1e7 + 7;

const int N = 1e5;


void solve()
{
    int cs = 1;
    int n, m;
    while (cin >> n) {
        // if (n == 0) break;
        cin >> m;
        vector<vector<int>> dp(n, vector<int>(n, mod));
        vector<pair<int,pii>> edges;
        vpi g[n];
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.pb({w, {u, v}});
            dp[u][v] = w;
            dp[v][u] = w;
        }
        for (int i = 0; i < n; i++) {
            dp[i][i] = 0;
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dp[i][j] = min(dp[i][k] + dp[k][j], dp[i][j]);
                }
            }
        }

        cout << "Set #" << cs++ << "\n";
        int q;
        cin >> q;
        while (q--) {
            int u, v;
            cin >> u >> v;
            int ans = mod;
            for(auto [w, it] : edges) {
                auto [x, y] = it;
                if (dp[u][v] < dp[u][x] + dp[v][y] + w) {
                    ans = min(ans, dp[u][x] + dp[v][y] + w);
                }
                else {
                    ans = min(ans, dp[u][x] + dp[v][y] + 3 * w);
                }
                swap(x, y);
                if (dp[u][v] < dp[u][x] + dp[v][y] + w) {
                    ans = min(ans, dp[u][x] + dp[v][y] + w);
                }
                else {
                    ans = min(ans, dp[u][x] + dp[v][y] + 3 * w);
                }
            }
            if (ans >= mod) {
                cout << "?\n";
            }
            else {
                cout << ans << "\n";
            }
        }
    }
}

signed main()
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    int cs = 1;
    while (t--) {
        //cout << "Case " << cs++ << ":" << " ";
        solve();
    }
}
