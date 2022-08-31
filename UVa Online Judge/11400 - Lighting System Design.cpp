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

struct node 
{
    int v, k, c, l;
    node(int a = 0, int b = 0, int c = 0, int d = 0) {v = a, k = b, this->c = c, l = d;}
    bool operator<(node a)
    {
        return v < a.v;
    }
};

void solve()
{
    int n;
    cin >> n;
    if (n == 0) return;
    
    vector<node> a(n + 1);
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i].v >> a[i].k >> a[i].c >> a[i].l;
    }
    sort(all(a));
   
    vi pre(n + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i].l;
    }
    
    int dp[n + 1];
    memset(dp, 0, sizeof dp);
    
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + a[i].k + a[i].c * a[i].l;
        for (int j = i - 1; j >= 1; j--) {
            dp[i] = min(dp[j - 1] + (pre[i] - pre[j - 1]) * a[i].c + a[i].k, dp[i]);
        }
    }
    
    cout << dp[n] << "\n";
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
