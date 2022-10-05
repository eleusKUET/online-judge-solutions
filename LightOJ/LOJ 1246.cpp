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

ll add(ll a, ll b)
{
    ll res = a + b;
    if (res >= mod) res -= mod;
    return res;
}

ll sub(ll a, ll b)
{
    ll res = a - b;
    if (res < 0) res += mod;
    if (res >= mod) res -= mod;
    return res;
}

ll mul(ll a, ll b)
{
    return (a * b)%mod;
}

ll modpow(ll a, ll b)
{
    if (b == 0) return 1%mod;
    ll u = modpow(a, b / 2);
    u = mul(u, u);
    if (b%2) u = mul(u, a);
    return u;
}

int fact[55];
int inv[55];

void preprocess()
{
    fact[0] = 1;
    for (int i = 1; i < 55; i++) {
        fact[i] = mul(fact[i - 1], i);
        inv[i] = modpow(fact[i], mod - 2);
    }
    inv[0] = modpow(fact[0], mod - 2);
}

ll ncr(ll a, ll b)
{
    return mul(fact[a], mul(inv[b], inv[a - b]));
}

int n, m, k;

int dp[20][20][55];


void solve()
{
    scanf("%d%d%d", &m, &n, &k);

    if (dp[m][n][k] != -1) {
        printf("%d\n", dp[m][n][k]);
        return;
    }

    int even = 0;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            even += (i + j)%2 == 0;
        }
    }
    int odd = (m + 1) * (n + 1) - even;

    int tot = 0;
    for (int i = 1; i <= k; i++) {
        int sum = 0;
        for (int j = i, par = 0; j > 0; j--, par++) {
            int sign = (par & 1) ? -1 : +1;
            sum = add(sum, sub(mul(sign, mul(ncr(i, j), modpow(j, even))), 0));
        }
        tot = add(tot, mul(ncr(k, i), mul(sum, modpow(k - i, odd))));
    }
    dp[m][n][k] = tot;
    printf("%d\n", tot);
}

signed main()
{
    // freopen("input.txt", "r", stdin);

    int t = 1;
    preprocess();
    memset(dp, -1, sizeof dp);
    scanf("%d", &t);
    int cs = 1;
    while (t--) {
        printf("Case %d: ", cs++);
        solve();
    }
}
