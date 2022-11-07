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


void solve(int cs)
{   
    int n;
    cin >> n;

    vi a(n), pre(n);

    for (int i = 1; i < n; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    int mx = -1e9;
    pii interval = pii(1,0);
    set<pii> s;
    s.insert(pii(pre[0], 0));

    for (int i = 1; i < n; i++) {
        auto [val, l] = *s.begin();
        int r = i + 1;
        int def = pre[i] - val;
        if (mx == def) {
            mx = def;
            if (r - l > interval.s - interval.f + 1) {
                interval = pii(l + 1, r);
            }
            else if (r - l == interval.s - interval.f + 1) {
                if (l + 1 < interval.f) interval = pii(l + 1, r);
            }
        }
        else if (mx < def) {
            mx = def;
            interval = pii(l + 1, r);
        }
        s.insert(pii(pre[i], i));
        // debug(l, r, interval, mx);
    }
    // debug(interval);
    if (mx > 0) {
        cout << "The nicest part of route "<< cs << " is between stops " << interval.f << " and " << interval.s << "\n";
    }
    else {
        cout << "Route " << cs << " has no nice parts\n";
    }
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
        solve(cs++);
    }
}
