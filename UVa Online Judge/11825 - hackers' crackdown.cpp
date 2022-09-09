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
int dp[1<<17];
int dq[1<<17];

void solve()
{
    int cs = 1;
    while (cin >> n && n) {
        memset(dp, 0, sizeof dp);
        memset(dq, 0, sizeof dq);
        vi a(n);
        
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            int num = 0;
            Setbit(num, i);
            for (int j = 0; j < k; j++) {
                int h;
                cin >> h;
                Setbit(num, h);
            }
            a[i] = num;
        }
       
        for (int i = 1; i < (1<<n); i++) {
            int num = 0;
            for (int j = 0; j < n; j++) {
                if (Checkbit(i, j)) {
                    num |= a[j];
                }
            }
            if (__builtin_popcount(num) == n) {
                dq[i] = num;
            }
        }
        for (int i = 0; i < (1<<n); i++) {
            for (int j = i; j; j = (j - 1) & i) {
                if (dq[j]) dp[i] = max(dp[i], dp[i ^ j] + 1);
            }
        }
        cout << "Case " << cs++ << ":" << " ";
        cout << dp[(1<<n) - 1] << "\n";
    }
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
