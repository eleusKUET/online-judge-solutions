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

string a;
int n;
int dp[1005][1005];
int dq[1005];

int f(int i)
{
    if (i < 1) return 0;
    if (dq[i] != -1) return dq[i];
    dq[i] = 2e9;
    for (int j = i; j >= 1; j--) {
        if (dp[j][i]) {
            dq[i] = min(dq[i], f(j - 1) + 1);
            debug(j, i);
        }
    }
    return dq[i];
}

void solve()
{
    cin >> a;
    n = a.size();
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 0;
        }
        dq[i] = -1;
    }
    a = "#" + a;
    for (int i = n; i >= 1; i--) {
        for (int j = i, k = i; j <= n && k >= 1; j++, k--) {
            if (j == k) dp[k][j] = 1;
            else if (dp[k + 1][j - 1] && a[k] == a[j]) dp[k][j] = 1;
        }
        for (int j = i + 1, k = i; j <= n && k >= 1; j++, k--) {
            if (k + 1 == j && a[k] == a[j]) dp[k][j] = 1;
            if (dp[k + 1][j - 1] && a[j] == a[k]) dp[k][j] = 1;
        }
    }
    
    cout << f(n) << "\n";
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
