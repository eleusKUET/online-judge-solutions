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
#define int long long 
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

unsigned ll dp[25][155];

void preprocess()
{
    dp[1][1] = 1;
    dp[1][2] = 1;
    dp[1][3] = 1;
    dp[1][4] = 1;
    dp[1][5] = 1;
    dp[1][6] = 1;
    for (int i = 2; i <= 24; i++) {
        for (int j = 1; j <= 150; j++) {
            for (int k = 1; k <= 6; k++) {
                if (j - k >= i - 1) dp[i][j] += dp[i - 1][j - k];
            }
        }
    }
}


void solve()
{
    int n, x;
    cin >> n >> x;

    if (n == 0 && x == 0) return;

    unsigned ll res, g, tmp, tot;
    tmp = 1;
    for (int i = 1; i <= n; i++) {
        tmp *= 6;
    }

    tot = 0;
    for (int i = 1; i < x; i++) {
        tot += dp[n][i];
    }
    debug(tot, n, x);
    g = __gcd(tmp - tot, tmp);

    if (tmp != g) cout << (tmp - tot) / g << "/" << tmp / g << "\n";
    else cout << (tmp - tot) / g << "\n";

    solve();
}

signed main()
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    preprocess();
    // cin >> t;
    int cs = 1;
    while (t--) {
        //cout << "Case " << cs++ << ":" << " ";
        solve();
    }
}
