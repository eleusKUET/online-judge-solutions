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

#ifdef __LOCAL__
#include "debug.h"
#else
#define debug(...)
#endif

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T> using Tree = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

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
    int n, m, s, t, p;
    cin >> n >> m >> s >> t >> p;
    
    vpl g[n + 5];
    vpl f[n + 5];
    vector<array<ll,3>> edge;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
        f[v].pb({u, w});
        edge.pb({u, v, w});
    }
    
    vll dist(n + 5, 1e9);
    priority_queue<pll> q;
    q.push({0, s});
    dist[s] = 0;
    
    while(q.size()) {
        auto [cost, u] = q.top();
        q.pop();
        
        if (-cost > dist[u]) continue;
        
        for (auto [v, w] : g[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                q.push({-dist[v], v});
            }
        }
    }
   
    vll distS = dist;
    dist = vll(n + 5, 1e9);
    q.push({0, t});
    dist[t] = 0;
    while(q.size()) {
        auto [cost, u] = q.top();
        q.pop();
        
        if (-cost > dist[u]) continue;
         
        for (auto [v, w] : f[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                q.push({-dist[v], v});
            }
        }
    }
    ll ans = -1;
    
    for (int i = 0; i < m; i++) {
        auto[x, y, w] = edge[i];
        debug(x, y, w);
        if (distS[x] + dist[y]  + w <= p) {
            ans = max(ans, w);
        }
    }   
    cout << ans << "\n";
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
