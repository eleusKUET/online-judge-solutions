// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>

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

struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
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

class Dsu
{
public:
    vector<int> sz;
    vector<int> parent;
    vector<int> sum;
    vector<int> dummy;
    int vogas;
    Dsu(int n)
    {
        sz.assign(n + 5, 1);
        parent.assign(n + 5, 0);
        sum.assign(n + 5, 0);
        dummy.assign(n + 5, 0);
        vogas = n;
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            dummy[i] = i;
            sum[i] = i;
        }
    }
    int Find(int u)
    {
        return parent[u] == u? u : parent[u] = Find(parent[u]);
    }
    bool Union(int u, int v)
    {
        int a = Find(dummy[u]), b = Find(dummy[v]);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b];
        sum[a] += sum[b];
        parent[b] = a; 
        return true;
    }
    int size_of(int u) 
    {
        return sz[Find(dummy[u])];
    }
    int sum_of(int u) {
        return sum[Find(dummy[u])];
    }
    void move(int u, int v) {
        int a = Find(dummy[u]);
        int b = Find(dummy[v]);
        if (a == b) return;
        sz[a]--;
        sum[a] -= u;
        dummy[u] = ++vogas;
        // debug(u, dummy[u], v, dummy[v]);
        sum[dummy[u]] = u;
        Union(u, v);
    }
};

const int mod = 1e9 + 7;

const int N = 1e5;


void solve()
{
    int n, m;
    while (cin >> n >> m) {
        Dsu dsu(n + m + 5);
        dsu.vogas = n;
        while (m--) {
            int t;
            cin >> t;
            if (t == 1) {
                int p, q;
                cin >> p >> q;
                dsu.Union(p, q);
            }
            else if (t == 2) {
                int p, q;
                cin>> p >> q;
                dsu.move(p, q);
            }
            else {
                int p;
                cin >> p;
                cout << dsu.size_of(p) << " " << dsu.sum_of(p) << "\n";
                // debug(dsu.dummy[p], p);
            }
        }
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
