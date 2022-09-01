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

const int N = 55;

int dp[N][N];
int n, l;
int a[N];

int f(int i, int j)
{
    if (i < 1 || j < 1 || i > n || j > n || i + 1 >= j) return 0;
    
    int &ret = dp[i][j];
    if (ret != -1) return ret;
    
    ret = 2e9;
    
    for (int k = i + 1; k < j; k++) {
        ret = min(ret, f(i, k) + f(k, j) + a[j] - a[i]);
    }
    
    return ret;
}

void solve()
{
    cin >> l;
    if (l == 0) return;
    cin >> n;
    for (int i = 0; i <= n + 2; i++) {
        for (int j = 0; j <= n + 2; j++) {
            dp[i][j] = -1;
        }
    }
    
    for (int i = 2; i <= n + 1; i++) {
        cin >> a[i];
    }
    a[1] = 0;
    a[n + 2] = l;
    n += 2;
    cout << "The minimum cutting is ";
    cout << f(1, n) << ".\n";
    solve();
}

signed main()
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    int cs = 1;
    while (t--) {
        //cout << "Case " << cs++ << ":" << " ";
        solve();
    }
}
