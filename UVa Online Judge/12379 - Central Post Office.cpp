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

const int mod = 1e9 + 7;

const int N = 1e5;


void solve()
{
    int n;
    scanf("%d", &n);
    vector<int> g[n + 5];

    for (int i = 1; i <= n; i++) {
        int k;
        scanf("%d", &k);
        int u = i;
        for (int j = 1; j <= k; j++) {
            int v;
            scanf("%d", &v);
            g[u].pb(v);
            g[v].pb(u);
        }
    }
    int dist[n + 5];
    int vis[n + 5];
    memset(dist, 0, sizeof dist);
    memset(vis, 0, sizeof vis);

    vis[1]++;

    function<void(int)> dfs = [&](int u) {
        for (auto v : g[u]) {
            if(vis[v]) continue;
            dist[v] = dist[u] + 1;
            vis[v]++;
            dfs(v);
        }
    };
    dfs(1);
    int mx = 1;
    for (int i = 1; i <= n; i++) {
        if (dist[mx] < dist[i]) mx = i; 
    }
    memset(dist, 0, sizeof dist);
    memset(vis, 0, sizeof vis);

    vis[mx]++;

    dfs(mx);
    mx = 1;
    for (int i = 1; i <= n; i++) {
        if (dist[mx] < dist[i]) mx = i; 
    }
    int ans = (n - 1) * 2 - dist[mx];

    printf("%d\n", ans);
}

signed main()
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    scanf("%d", &t);
    int cs = 1;
    while (t--) {
        //cout << "Case " << cs++ << ":" << " ";
        solve();
    }
}
