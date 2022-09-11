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

int n;
vi g[205];
map<string,int> rep;
int dp[205][2];
int cnt[205][2];

void dfs(int u)
{
    dp[u][0] = 1;
    cnt[u][0] = 1;
    cnt[u][1] = 1;
    for (auto v : g[u]) {
        dfs(v);
        dp[u][0] += dp[v][1];
        dp[u][1] += max(dp[v][0], dp[v][1]);
        if (dp[v][1] == dp[v][0]) cnt[u][1] = max(cnt[u][1], 2);
        else if (dp[v][1] > dp[v][0]) {
            cnt[u][1] = max(cnt[u][1], cnt[v][1]);
        }
        else {
            cnt[u][1] = max(cnt[v][0], cnt[u][1]);
        }
        cnt[u][0] = max(cnt[u][0], cnt[v][1]);
    }
}

void solve()
{
    cin >> n;
    if (n == 0) return;
    rep.clear();
    for (int i = 0; i <= n; i++) {
        g[i].clear();
        dp[i][0] = dp[i][1] = 0;
        cnt[i][0] = cnt[i][1] = 0;
    }
    
    string h;
    cin >> h;
    
    int id = 0;
    rep[h] = ++id;
    
    for (int i = 2; i <= n; i++) {
        string child, par;
        cin >> child >> par;
        if(rep.find(par) == rep.end()) rep[par] = ++id;
        if(rep.find(child) == rep.end()) rep[child] = ++id;
        g[rep[par]].pb(rep[child]);
    }
    
    dfs(1);
    if (dp[1][0] == dp[1][1]) {
        cout << dp[1][0] << " No\n";
    }
    else if (dp[1][0] > dp[1][1]) {
        cout << dp[1][0] << " " << ((cnt[1][0] == 1) ? "Yes\n" : "No\n");
    }
    else {
        cout << dp[1][1] << " " << ((cnt[1][1] == 1) ? "Yes\n" : "No\n");
    }
    solve();
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
