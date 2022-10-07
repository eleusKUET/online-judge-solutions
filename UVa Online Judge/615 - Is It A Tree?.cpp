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

const int mod = 1e9 + 7;

const int N = 1e5;

vi g[N + 5];
int in[N + 5];
int vis[N + 5];

void solve()
{
    int cs = 1;
    while (true) {
        vpi edge;
        int u, v;
        while (cin >> u >> v) {
            if (u == 0 && v == 0) {
                break;
            }
            if (u == -1 && v == -1) return;
            edge.pb({u, v});
        }
        if (edge.empty()) {
            cout << "Case " << cs++ << " is a tree.\n";
            continue;
        }
        set<int> un;

        for (auto [x, y] : edge) {
            g[x].clear();
            g[y].clear();
            in[x] = in[y] = vis[x] = vis[y] = 0;
            un.insert(x);
            un.insert(y);
        }

        bool bad = false;

        for (auto [u, v] : edge) {
            g[u].pb(v);
            in[v]++;
        }

        queue<int> q;
        for (auto it : un) {
            if (in[it] == 0) q.push(it), vis[it] = 1;
            else if (in[it] > 1) bad = true;
        }
        if (q.size() != 1) {
            bad = true;
        }

        cout << "Case " << cs++ << " ";
        if (bad) {
            cout << "is not a tree.\n";
            continue;
        }

        while (q.size()) {
            int u = q.front();
            q.pop();

            for (auto it : g[u]) {
                vis[it] = 1;
                q.push(it);
            }
        }

        for (auto it : un) {
            if (vis[it] == 0) bad = true;
        }
        if (!bad) {
            cout << "is a tree.\n";
        }
        else {
            cout << "is not a tree.\n";
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
