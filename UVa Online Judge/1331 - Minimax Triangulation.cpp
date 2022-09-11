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

#define eps 1e-4

const int mod = 1e9 + 7;

const int N = 1e5;

double area(int x1, int y1, int x2, int y2, int x3, int y3)
{
    x2 -= x1;
    x3 -= x1;
    y2 -= y1;
    y3 -= y1;
    double area = 0.5 * abs(x2 * y3 - x3 * y2);
    return area;
}

double dp[55][55];
int X[55];
int Y[55];
int n;

bool check(int i, int j, int k)
{
    double a = area(X[i], Y[i], X[j], Y[j], X[k], Y[k]);
    for (int x = 0; x < n; x++) {
        if (x == i || x == j || x == k) continue;
        double tmp = area(X[i], Y[i], X[j], Y[j], X[x], Y[x]);
        double sum = tmp;
        tmp = area(X[i], Y[i], X[k], Y[k], X[x], Y[x]);
        sum += tmp;
        tmp = area(X[k], Y[k], X[j], Y[j], X[x], Y[x]);
        sum += tmp;
        
        if (abs(sum - a) < eps) return true;
    }
    return false;
}

double f(int x, int y)
{    
    double &ret = dp[x][y];
    if (ret != -1.0) return ret;
    
    ret = 1e9;
    
    
    for (int i = (x + 1)%n; i != y; i = (i + 1)%n) {
        
        if (check(x, y, i)) continue;
        
        double tmp = area(X[x], Y[x], X[i], Y[i], X[y], Y[y]);
        debug(tmp, x, i, y);
        if ((x + 1)%n != i) tmp = max(tmp, f(x, i));
        if ((i + 1)%n != y) tmp = max(tmp, f(i, y));
        
        ret = min(ret, tmp);
    }
    return ret;
}

void solve()
{
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> X[i] >> Y[i];
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = -1.0;
        }
    }
    
    cout << setprecision(1) << fixed << f(0, n - 1) << "\n";
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
