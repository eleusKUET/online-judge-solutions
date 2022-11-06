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

class frac
{
public:
    long long up, down;
    frac(long long u = 0, long long d = 1) {
        up = u; down = d; long long g = __gcd(abs(u), abs(d));
        up /= g, down /= g; 
        if (up == 0) down = abs(down); 
        if (down < 0) up = -up, down = -down;
    }
    frac &operator=(long long a){frac tmp(a); up = tmp.up, down = tmp.down; return tmp;}
    frac operator+(frac a) {return frac(up * a.down + down * a.up, a.down * down);}
    frac operator-(frac a) {return frac(up * a.down - down * a.up, a.down * down);}
    frac operator*(frac a) {return frac(up * a.up, down * a.down);}
    frac operator/(frac a) {return frac(up * a.down, down * a.up);}
    frac &operator+=(frac &a) {frac res = frac(up * a.down + down * a.up, a.down * down); this->up = res.up; this->down = res.down; return *this;}
    frac &operator-=(frac &a) {frac res = frac(up * a.down - down * a.up, a.down * down); this->up = res.up; this->down = res.down; return *this;}
    frac &operator*=(frac &a) {frac res = frac(up * a.up, down * a.down); this->up = res.up; this->down = res.down; return *this;}
    frac &operator/=(frac &a) {frac res = frac(up * a.down, down * a.up); this->up = res.up; this->down = res.down; return *this;}
    string out() {if (up == 0) return "0"; if (down == 1) return to_string(up); return to_string(up) + "/" + to_string(down);}
    bool operator<(const frac a) const {return up * a.down < down * a.up;}
    bool operator<=(const frac a) const {return up * a.down <= down * a.up;}
    bool operator>(const frac a) const {return up * a.down > down * a.up;}
    bool operator>=(const frac a) const {return up * a.down >= down * a.up;}
    bool operator==(const frac a) const {return up * a.down == down * a.up;}
};

const int mod = 1e9 + 7;

const int N = 1e5;


void solve()
{
    int x, y;
    char ch;
    char equ;
    string p, q;

    map<string,int> rep;
    int id = 0;

    vector<pair<int,frac>> g[100];

    auto getId = [&](string a) {
        return rep[a] ? rep[a] : rep[a] = ++id;
    };

    while (cin >> ch) {
        if (ch == '.') break;

        if (ch == '!') {
            cin >> x >> p >> equ >> y >> q;
            int u = getId(p);
            int v = getId(q);
            g[u].pb({v, frac(x, y)});
            g[v].pb({u, frac(y, x)});
        }
        else {
            cin >> p >> equ >> q;
            int u = getId(p);
            int v = getId(q);

            vector<frac> res(rep.size() + 5);
            vector<int> vis(rep.size() + 5);

            function<void(int,frac)> dfs = [&](int u, frac cnt) {
                if (vis[u]) return;
                vis[u]++;
                res[u] = cnt;
                for (auto [v, w] : g[u]) {
                    dfs(v, cnt * w);
                }
            };  
            dfs(u, 1);
            
            if (vis[v]) cout << res[v].up << " " << p << " = " << res[v].down << " " << q << "\n";
            else cout << "? " << p << " = ? " << q << "\n"; 
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
