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

int m, n;
vector<string> a(130);

int dp[1<<12][1<<12];

int f(int mask, int format)
{
    if (dp[mask][format] != -1) return dp[mask][format];
    
    int cnt = 0;
    
    for (int i = 0; i < n; i++) {
        bool ok = true;
        for (int j = 0; j < m; j++) {
            if (Checkbit(mask, j)) {
                if (Checkbit(format, j) + '0' != a[i][j]) {
                    ok = false;
                    break;
                }
            }
        }
        cnt += ok;
    }
    
    if (cnt == 1) {
        return dp[mask][format] = 0;
    }
    cnt = 10000;
    for (int i = 0; i < m; i++) {
        if (Checkbit(mask, i)) continue;
        cnt = min(cnt, max({1 + f(mask | (1<<i), format | (1<<i)), 1 + f(mask | (1<<i), format)}));
    }
    
    return dp[mask][format] = cnt;
}

void solve()
{
    cin >> m;
    cin >> n;
    if (m == 0 && n == 0) return;
 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    memset(dp, -1, sizeof dp);
    
    cout << f(0, 0) << "\n";
    
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
