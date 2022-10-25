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

int n;
string s;

int dp[1<<12];

int f(int mask)
{
    if (mask == 0) return 0;
    int ret = dp[mask];
    if (ret != -1) return ret;

    ret = 0;
    for (int i = 2; i < n; i++) {
        if (Checkbit(mask, i) && Checkbit(mask, i - 1) && !Checkbit(mask, i - 2)) {
            Setbit(mask, i);
            Setbit(mask, i - 1);
            Setbit(mask, i - 2);
            ret = max(ret, 1 + f(mask));
            Setbit(mask, i);
            Setbit(mask, i - 1);
            Setbit(mask, i - 2);
        }
        if (!Checkbit(mask, i) && Checkbit(mask, i - 1) && Checkbit(mask, i - 2)) {
            Setbit(mask, i);
            Setbit(mask, i - 1);
            Setbit(mask, i - 2);
            ret = max(ret, 1 + f(mask));
            Setbit(mask, i);
            Setbit(mask, i - 1);
            Setbit(mask, i - 2);
        }
    }
    return dp[mask] = ret;
}

void solve()
{
    cin >> s;
    n = s.size();

    memset(dp, -1, sizeof dp);
    int mask = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'o') Setbit(mask, i), cnt++;
    }

    cout << cnt - f(mask) << "\n";
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
