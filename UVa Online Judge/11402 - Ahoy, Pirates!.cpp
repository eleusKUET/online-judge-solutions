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

#ifndef ONLINE_JUDGE
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

class segTree
{
    vector<int> tree[2];
    vector<char> lazy;
public:
    segTree(int n)
    {
        tree[0].assign(n * 4 + 5, 0);
        tree[1].assign(n * 4 + 5, 0);
        lazy.assign(n * 4 + 5, '0');
    }
    void propagate(int v, int tl, int tr)
    { 
        int sum = tree[0][v] + tree[1][v];
        if (lazy[v] == 'E') {
            tree[0][v] = 0;
            tree[1][v] = sum;
            if (tl != tr) {
                lazy[v * 2] = lazy[v * 2 + 1] = lazy[v];
            }
            lazy[v] = '0';
        }
        else if (lazy[v] == 'F') {
            tree[1][v] = 0;
            tree[0][v] = sum;
            if (tl != tr) {
                lazy[v * 2] = lazy[v * 2 + 1] = lazy[v];
            }
            lazy[v] = '0';
        }
        else if (lazy[v] == 'I') {
            swap(tree[0][v], tree[1][v]);
            if (tl != tr) {
                if (lazy[v * 2] == 'E') lazy[v * 2] = 'F';
                else if (lazy[v * 2] == 'F') lazy[v * 2] = 'E';
                else if (lazy[v * 2] == 'I') lazy[v * 2] = '0';
                else lazy[v * 2] = 'I';
                
                if (lazy[v * 2 + 1] == 'E') lazy[v * 2 + 1] = 'F';
                else if (lazy[v * 2 + 1] == 'F') lazy[v * 2 + 1] = 'E';
                else if (lazy[v * 2 + 1] == 'I') {
                    lazy[v * 2 + 1] = '0';
                }
                else {
                    lazy[v * 2 + 1] = 'I';
                }
            }
            lazy[v] = '0';
        }
    }
    int rangeQuery(int v, int tl, int tr, int l, int r)
    {
        propagate(v, tl, tr);
        if (l > tr || tl > r) return 0;
        if (l <= tl && tr <= r) {
            return tree[0][v];
        }
        int mid = (tl + tr) / 2;
        return rangeQuery(v * 2, tl, mid, l, r) + rangeQuery(v * 2 + 1, mid + 1, tr, l, r);
    }
    void rangeUpdate(int v, int tl, int tr, int l, int r, char x)
    {
        propagate(v, tl, tr);
        if (l > tr || tl > r) return;
        if (l <= tl && tr <= r) {
            lazy[v] = x;
            propagate(v, tl, tr);
            return;
        }
        int mid = (tl + tr) / 2;
        rangeUpdate(v * 2, tl, mid, l, r, x);
        rangeUpdate(v * 2 + 1, mid + 1, tr, l, r, x);
        tree[0][v] = tree[0][v * 2] + tree[0][v * 2 + 1];
        tree[1][v] = tree[1][v * 2] + tree[1][v * 2 + 1];
    }
    void build(int v, int tl, int tr, string &a) 
    {
        if (tl == tr) {
            if (a[tl] == '1') {
                tree[0][v] = 1;
            }
            else {
                tree[1][v] = 1;
            }
            return;
        }
        int mid = (tl + tr) / 2;
        build(v * 2, tl, mid, a);
        build(v * 2 + 1, mid + 1 , tr, a);
        
        tree[0][v] = tree[0][v * 2] + tree[0][v * 2 + 1];
        tree[1][v] = tree[1][v * 2] + tree[1][v * 2 + 1];
    }
};

void solve()
{
    int m;
    cin >> m;
    string a;
    
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        string tmp;
        cin >> tmp;
        while (t--) {
            a += tmp;
        }
    }
    int n = a.size();
    a = "#" + a;
    
    segTree x(n);

    x.build(1, 1, n, a);
    
    int q;
    cin >> q;
    for(int i = 1, j = 1; i <= q; i++) {
        
        char c;
        int l, r;
        cin >> c >> l >> r;
        l++, r++;
        
        if (c == 'S') {
            cout << "Q" << j++ << ":" << " ";
            cout << x.rangeQuery(1, 1, n, l, r) << "\n";
        }
        else {
            x.rangeUpdate(1, 1, n, l, r, c);
        }
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
        cout << "Case " << cs++ << ":" << "\n";
        solve();
    }
}
