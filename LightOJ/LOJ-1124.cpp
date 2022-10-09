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

const int mod = 1e8 + 7;

long long add(long long a, long long b)
{
    long long res = a + b;
    if (res < 0) res += mod;
    if (res >= mod) res -= mod;
    return res;
}

long long sub(long long a, long long b)
{
    long long res = a - b;
    if (res < 0) res += mod;
    if (res >= mod) res -= mod;
    return res;
}

long long mul(long long a, long long b)
{
    long long res = (a * b) % mod;
    if (res < 0) res += mod;
    return res;
}

long long modpow(long long a, long long b)
{
    if (b == 0) return 1%mod;
    long long u = modpow(a, b / 2);
    u = mul(u, u);
    if (b & 1) u = mul(u, a);
    return u;
}

struct Combi {
    vector<int> facts;
    vector<int> invs;
    vector<int> finvs;
    int sz;
    Combi(int n) {
        sz = n;
        facts.assign(n + 5, 0);
        invs.assign(n + 5, 0);
        finvs.assign(n + 5, 0);
        facts[0] = finvs[0] = invs[1] = 1;
        for (int i = 2; i <= n; i++) invs[i] = sub(mod, mul(mod / i, invs[mod%i]));
        for (int i = 1; i <= n; i++) {
            facts[i] = mul(facts[i - 1], i);
            finvs[i] = mul(finvs[i - 1], invs[i]);
        }
    }
    inline int fact(int n){return facts[n];}
    inline int inv(int n) {return invs[n];}
    inline int finv(int n){return finvs[n];}
    inline int ncr(int n, int r){return mul(facts[n], mul(finvs[r], finvs[n - r]));}
};

const int N = 1e6;

Combi C(N);

int k, n;

int upper[12], lower[12];
int lo[12];

int stars_and_bars()
{
    int p = n;
    for (int i = 0; i < k; i++) {
        p -= lo[i];
    }
    if (p < 0) return 0;
    return C.ncr(p + k - 1, k - 1);
}


void solve()
{
    cin >> k >> n;

    for (int i = 0; i < k; i++) {
        cin >> lower[i] >> upper[i];
    }

    ll ans = 0;
    for (int i = 0; i < (1<<k); i++) {
        for (int j = 0; j < k; j++) {
            if (Checkbit(i, j)) {
                lo[j] = upper[j] + 1;
            }
            else {
                lo[j] = lower[j];
            }
        }
        if (__builtin_popcount(i)%2 == 0) {
            ans = add(ans, stars_and_bars());
        }
        else {
            ans = sub(ans, stars_and_bars());
        }
        //debug(stars_and_bars(), i);
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
        cout << "Case " << cs++ << ":" << " ";
        solve();
    }
}
