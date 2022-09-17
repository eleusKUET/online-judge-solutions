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

#define eps 1e-12

const int mod = 1e9 + 7;

const int N = 1e5;

int n;
double A;

bool feasible(double A1)
{
    double a[n];
    a[0] = A;
    a[1] = A1;
    
    for (int i = 2; i < n; i++) {
        a[i] = a[i - 1] * 2.0 + 2.0 - a[i - 2];
        if (a[i] < 0.0) return false;
    }
    return true;
}

void solve()
{
    while (cin >> n >> A) {
        // if (n == 0) break;
        double lo = 0.0;
        double hi = A;
        
        double ans = -1;
        
        while (hi - lo > eps) {
            double mid = (lo + hi) / 2.0;
            
            if (feasible(A - mid)) {
                lo = mid;
                ans = A - mid;
            }
            else {
                hi = mid;
            }
        }
        cout << setprecision(2) << fixed;
        // cout << ans << "\n";
        
        double a[n];
        a[0] = A;
        a[1] = ans;
        
        for (int i = 2; i < n; i++) {
            a[i] = a[i - 1] * 2.0 + 2.0 - a[i - 2];
            assert(a[i] >= 0.0);
        }
        
        cout << a[n - 1] << "\n";
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
