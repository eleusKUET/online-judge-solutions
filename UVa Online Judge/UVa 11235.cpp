#include "bits/stdc++.h"
using namespace std;
#define int long long 
const int N = 1e5 + 5;
 
struct data {
    int pre, pre_val, suf_val, suf, ans;
};

void print(data a)
{
    cout << "{a.pre, a.suf, a.pre_val, a.suf_val, a.ans} = " << "{"
        << a.pre << ", " << a.suf << ", " << a.pre_val << ", " << a.suf_val
        << ", " << a.ans << "}\n";
}
 
data tree[N * 4];
 
data convert(int val)
{
    data res;
    res.pre = res.suf = 1;
    res.pre_val = res.suf_val = val;
    res.ans = 1;
    
    return res;
}
 
data combine(data a, data b)
{
    data res;
    res.ans = max(a.ans, b.ans);
    
    if (a.suf_val == b.pre_val) {
        res.ans = max(res.ans, a.suf + b.pre);
    }
    res.pre = a.pre;
    res.pre_val = a.pre_val;
    if (a.pre_val == b.pre_val) {
        res.pre = a.pre + b.pre;
    }
    res.suf = b.suf;
    res.suf_val = b.suf_val;
    if (a.suf_val == b.suf_val) {
        res.suf = a.suf + b.suf;
    }
    return res;
}
 
int a[N];
int n;
 
void build(int v, int tl, int tr)
{
    if (tl == tr) {
        tree[v] = convert(a[tl]);
        // cout << "[tl, tr] = " << "[" << tl << ", " << tr <<  "]\n";
        // print(tree[v]);
        return;
    }   
    int mid = (tl + tr) / 2;
    build(v * 2, tl, mid);
    build(v * 2 + 1, mid + 1, tr);
    tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
    // cout << "[tl, tr] = " << "[" << tl << ", " << tr <<  "]\n";
    // print(tree[v]);
}
 
data query(int v, int tl, int tr, int l, int r)
{
    if (l > r) {
        data res = convert(1000000007);
        res.pre = 0;
        res.suf = 0;
        // cout << "[tl, tr] = " << "[" << tl << ", " << tr <<  "]\n";
        // print(res);
        return res;
    }
    if (tl == l && tr == r) {
        // cout << "[tl, tr] = " << "[" << tl << ", " << tr <<  "]\n";
        // print(tree[v]);
        return tree[v];
    }
    int mid = (tl + tr) / 2;
    data left = query(v * 2, tl, mid, l, min(mid, r));
    data right = query(v * 2 + 1, mid + 1, tr, max(l, mid + 1), r);
    data res = combine(left, right);
    
    // cout << "marge[tl, tr] = " << "[" << tl << ", " << tr <<  "]\n";
    // print(res);
    return res;
}

 
void solve()
{
    int m;
    cin >> n;
    if (n == 0) {
        return;
    }
    cin >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    
    while (m--) {
        int l, r;
        cin >> l >> r;
        data ask = query(1, 1, n, l, r);
        
        cout << ask.ans << "\n";
    }
    solve();
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
