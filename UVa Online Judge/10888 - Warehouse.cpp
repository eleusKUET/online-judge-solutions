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

const int mod = 1e5 + 7;

const int N = 1e5;


void solve()
{
    int n, m;
    cin >> n >> m;

    vector<string> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vpi b, x;
    map<pii,int> rep;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'B') {
                b.pb({i, j});
            }
            if (a[i][j] == 'X') {
                x.pb({i, j});
            }
        }
    }

    function<int(int,int)> yo = [&](int l, int r) {
        vector<vector<int>> vis(n, vi(m));
        auto [ux, uy] = b[l];
        vis[ux][uy] = 1;
        queue<pii> q;
        q.push(b[l]);
        while (q.size()) {
            auto [ux, uy] = q.front();
            q.pop();
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (abs(dx) == abs(dy)) continue;
                    int vx = dx + ux;
                    int vy = dy + uy;
                    if (vx >= 0 && vx < n && vy >= 0 && vy < m && a[vx][vy] != '#' && !vis[vx][vy]) {
                        vis[vx][vy] = vis[ux][uy] + 1;
                        q.push({vx, vy});
                    }
                }
            }
        }
        auto [vx, vy] = x[r];
        return vis[vx][vy] ? vis[vx][vy] - 1 : mod;
    };

    int id = 0;
    for (auto it : b) {
        rep[it] = ++id;
    }
    for (auto it : x) {
        rep[it] = ++id;
    }

    vector<vector<int>> edge;

    for (int i = 0; i < b.size(); i++) {
        for (int j = 0; j < x.size(); j++) {
            edge.pb({rep[b[i]], rep[x[j]], yo(i, j), 1});
            // debug(i, b[i], j, x[j], yo(i, j));
        }
    }

    int sz = id + 2;
    for (auto it : b) {
        edge.pb({0, rep[it], 0, 1});
    }
    for (auto it : x) {
        edge.pb({rep[it] + sz, sz, 0, mod});
        edge.pb({rep[it], rep[it] + sz, 0, 1});
    }

    vector<vector<int>> cap(sz * 3, vi(sz * 3));
    vector<vector<int>> adj(sz * 3);
    vector<vector<int>> weight(sz * 3, vi(sz * 3));
    vector<int> pi(sz * 3, mod);
    vector<int> par(sz * 3);
    vector<int> dist(sz * 3, mod);

    for (auto it : edge) {
        // debug(it);
        int u = it[0];
        int v = it[1];
        int cost = it[2];
        int c = it[3];
        cap[u][v] = c;
        weight[u][v] = cost;
        weight[v][u] = -cost;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    function<int(int,int)> dijk = [&] (int s, int t) {
        priority_queue<pii> q;
        fill(all(dist), mod);
        fill(all(par), -1);
        dist[s] = 0;
        par[s] = s;
        q.push({0, s});
        while (q.size()) {
            auto [cost, u] = q.top();
            q.pop();
            cost = -cost;
            if (dist[u] < cost) continue;
            for (auto v : adj[u]) {
                int dv = dist[u] + pi[u] - pi[v] + weight[u][v];
                if (cap[u][v] && dist[v] > dv) {
                    dist[v] = dv;
                    par[v] = u;
                    q.push({-dist[v], v});
                }
            }
        }
        return dist[t];
    };  

    pi[0] = 0;

    for (int i = 1; i <= sz * 3; i++) {
        for (auto it : edge) {
            int u = it[0];
            int v = it[1];
            int cost = it[2];
            int c = it[3];
            if (pi[u] < mod && pi[v] > pi[u] + cost) {
                pi[v] = pi[u] + cost;
            }
        }
    }

    int s = 0, t = sz;
    int d;
    int flow = 0;
    int mncost = 0;
    while ((d = dijk(s, t)) < mod) {
        d -= pi[s] - pi[t];
        int cur = t;
        int mnflow = mod;
        while (cur != s) {
            int prev = par[cur];
            mnflow = min(cap[prev][cur], mnflow);
            cur = prev;
        }
        cur = t;
        while (cur != s) {
            int prev = par[cur];
            cap[prev][cur] -= mnflow;
            cap[cur][prev] += mnflow;
            cur = prev;
        }
        mncost += d * mnflow;
        flow += mnflow;
        for (int i = 0; i < sz * 3; i++) {
            pi[i] += dist[i];
        }
    }

    cout << mncost << "\n";
}

signed main()
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    int cs = 1;
    while (t--) {
        //cout << "Case " << cs++ << ":" << " ";
        solve();
    }
}
