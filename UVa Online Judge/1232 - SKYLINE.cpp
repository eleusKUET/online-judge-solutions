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

int ans;

class segTree
{
    vector<int> tree;
    vector<int> mn;
    vector<int> lazy;
public:
    segTree(int n)
    {
        tree.assign(n * 4 + 5, 0);
        lazy.assign(n * 4 + 5, 0);
        mn.assign(n * 4 + 5, 0);
    }
    void rangeUpdate(int v, int tl, int tr, int l, int r, int x)
    {
        if (l > tr || tl > r) return;
        if (lazy[v] != 0) {
            if (tl != tr) {
                lazy[v * 2] = lazy[v];
                lazy[v * 2 + 1] = lazy[v];
            }
            tree[v] = lazy[v];
            mn[v] = lazy[v];
            lazy[v] = 0;
        }
        if (mn[v] > x) return;
        if (l <= tl && tr <= r) {
            if (tree[v] <= x) {
                ans += (tr - tl + 1);
                tree[v] = x;
                mn[v] = x;
                lazy[v] = x;
                return;
            }
            if (tl == tr) return;
        }
        int mid = (tl + tr) / 2;
        rangeUpdate(v * 2, tl, mid, l, r, x);
        rangeUpdate(v * 2 + 1, mid + 1, tr, l, r, x);
        tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
        mn[v] = min(mn[v * 2], mn[v *2 + 1]);
    }
};

const int mod = 1e9 + 7;

const int N = 1e5;

void solve()
{
    int n;
    cin >> n;

    segTree s(N);
    ans = 0;

    for (int i = 1; i <= n; i++) {
        int l, r, h;
        cin >> l >> r >> h;
        s.rangeUpdate(1, 1, N, l, r - 1, h);
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
        //cout << "Case " << cs++ << ":" << " ";
        solve();
    }
}
