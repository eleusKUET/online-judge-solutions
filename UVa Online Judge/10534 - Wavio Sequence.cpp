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

class BIT
{
    vector<int> tree;
    int n;
public:
    BIT(int sz, int val = 0) 
    {
        tree.assign(sz + 5, val);
        n = sz;
    }
    void update(int pos, int val)
    {
        while (pos <= n) {
            tree[pos] = max(tree[pos], val);
            pos += pos & -pos;
        }
    }
    void update(int l, int r, int val)
    {
        update(l, val);
        update(r + 1, -val);
    }
    int query(int l) 
    {
        int sum = 0;
        while (l > 0) {
            sum = max(sum, tree[l]);
            l -= l & -l;
        }
        return sum;
    }
    int query(int l, int r)
    {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};

const int mod = 1e9 + 7;

const int N = 1e5;


void solve()
{
    int n;
    while (cin >> n && n) {
        map<int,int> rep;
        vi a(n + 5);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            rep[a[i]];
        }
        int id = 0;
        for (auto &it : rep) {
            it.s = ++id;
        }
        for (int i = 1; i <= n; i++) {
            a[i] = rep[a[i]];
        }

        vector<int> dp(n + 4, 1), dq(n + 5, 1);

        BIT s(n);

        for (int i = 1; i <= n; i++) {
            dp[i] = max(dp[i], s.query(a[i] - 1) + 1);
            s.update(a[i], dp[i]);
        }
        s = BIT(n);
        for (int i = n; i >= 1; i--) {
            dq[i] = max(dq[i], s.query(a[i] - 1) + 1);
            s.update(a[i], dq[i]);
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, min(dp[i], dq[i]) * 2 - 1);
        }

        cout << ans << "\n";
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
