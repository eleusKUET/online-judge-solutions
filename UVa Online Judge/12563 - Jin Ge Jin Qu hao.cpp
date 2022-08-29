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

#ifndef ONLINE_JUDGE
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
    int n, t;
    cin >> n >> t;
    
    auto a = vector<ll>(n + 1);
    int dp[10005];
    memset(dp, 0, sizeof dp);
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 10000; j >= 0; j--) {
            if (j == 0 || dp[j]) {
                if (j + a[i] <= 10000) dp[j + a[i]] = max(dp[j + a[i]], dp[j] + 1);
            } 
        }
    }
    int cnt = 0;
    for (int i = min(10000, t - 1); i >= 0; i--) {
        if (cnt < dp[i]) {
            cnt = dp[i];
            ans = i;
        }
    }
    cout << cnt + 1 << " " << ans + 678 << "\n";
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
        cout << "Case " << cs++ << ":" << " ";
        solve();
    }
}
