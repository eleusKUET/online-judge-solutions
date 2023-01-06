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
    int n, e;
    while (cin >> n >> e) {
        int s, t;
        cin >> s >> t;

        vector<vector<int>> edge;
        for (int i = 1; i <= e; i++) {
            int u, v;
            double r, d;
            cin >> u >> v >> r >> d;
            int R = r * 10;
            int D = d * 10;
            edge.pb({u, v, R, D});
        }

        vector<int> par(n + 5, -1);

        function<int(int)> dijk = [&](int temp) {
            vpi g[n + 5];
            for (auto it : edge) {
                int u = it[0];
                int v = it[1];
                int R = it[2];
                int D = it[3];
                if (R <= temp) {
                    g[u].pb({v, D});
                    g[v].pb({u, D});
                }
            }
            vector<int> dist(n +5, mod);
            priority_queue<pii> q;
            q.push({0, s});
            dist[s] = 0;
            par[s] = s;
            while (q.size()) {
                auto [cost, u] = q.top();
                q.pop();
                cost  *= -1;
                if (dist[u] < cost) continue;
                for (auto [v, w] : g[u]) {
                    if (dist[v] > dist[u] +w) {
                        dist[v] = dist[u] + w;
                        q.push({-dist[v], v});
                        par[v] = u;
                    }
                }
            }
            return dist[t];
        };

        int lo = 200;
        int hi = 500;
        int ans = hi;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int res = dijk(mid);
            if (res < mod) {
                ans = mid;
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }

        int dist = dijk(ans);
        vector<int> path;
        int cur = t;
        while (cur != s) {
            path.pb(cur);
            cur = par[cur];
        }
        path.pb(cur);
        reverse(all(path));
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << " \n"[i + 1 == path.size()];
        }
        cout << setprecision(1) << fixed << dist / 10.0 << " " << ans / 10.0 << "\n";
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
