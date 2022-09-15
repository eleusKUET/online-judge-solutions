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


void solve()
{
    ll n, s1, v1, s2, v2;
    cin >> n >> s1 >> v1 >> s2 >> v2;
    
    ll lcm = s2 * s1 / __gcd(s2, s1);
    ll ans = 0;
    
    if (n >= 2 * lcm) {
        ans += (n / lcm - 1) * max((lcm / s1) * v1, (lcm / s2) * v2);
        n %= lcm;
        n += lcm;
    }
    if (s1 < s2) {
        swap(s1, s2);
        swap(v1, v2);
    }
    ll tmp = 0;
    for (ll i = 0; i * s1 <= n; i++) {
        ll take = i * v1;
        ll other = (n - i * s1) / s2;
        tmp = max(take + other * v2, tmp);
        debug(other, take, ans, lcm);
    }
    
    cout << tmp + ans << "\n";
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
        cout << "Case #" << cs++ << ":" << " ";
        solve();
    }
}
