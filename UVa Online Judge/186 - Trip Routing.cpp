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

const int mod = 1e7 + 7;

const int N = 1e5;

struct edge {
    string uname, vname, route;
    int u, v, w;
    edge(){}
    edge(string a, string b, string c, int d, int e, int f) {
        uname = a; vname =  b; route = c; u = d; v = e; w = f;
    }
};

vector<string> split(char *str)
{
    char *tok = strtok(str, ",");
    vector<string> res;
    while (tok != NULL) {
        res.pb(tok);
        tok = strtok(NULL, ",");
    }
    return res;
}

void solve()
{
    char input[500];
    int id = 0;
    map<string,int> node;
    map<int,string> lebel;

    auto Node = [&] (string s) {
        if (node.find(s) != node.end()) return node[s];
        node[s] = ++id;
        lebel[node[s]] = s;
        return node[s];
    };

    auto Lebel = [&] (int node) {
        return lebel[node];
    };

    vector<edge> edges;

    while (gets(input)) {
        if (strlen(input) == 0) break;

        auto res = split(input);
        edge tmp(res[0], res[1], res[2], Node(res[0]), Node(res[1]), atoi(res[3].c_str()));
        edges.pb(tmp);
    }

    vpi dd;
    while (gets(input)) {
        if (strlen(input) == 0) break;
        auto res = split(input);
        dd.pb({Node(res[0]), Node(res[1])});
    }

    vector<edge> g[id + 4];

    for (edge it : edges) {
        g[it.u].pb(it);
        swap(it.u, it.v);
        swap(it.uname, it.vname);
        g[it.u].pb(it);
    }

    vector<edge> cache;

    function<void(int,int,int, vi&)> Report = [&] (int From, int To, int cost, vi& par) {
        int cur = To;
        vector<edge> path;
        while (cur != From) {
            int prev = par[cur];
            path.pb(cache[cur]);
            cur = prev;
        }
        //debug(From, To, cost);
        reverse(all(path));
        printf("\n\n%-20s %-20s %-10s %s\n", "From", "To", "Route", "Miles");
        string pretty(20, '-');
        printf("%20s %20s %10s %5s\n", pretty.c_str(), pretty.c_str(), pretty.substr(0, 10).c_str(), pretty.substr(0, 5).c_str());
        for (auto it : path) {
            printf("%-20s %-20s %-10s %5d\n", it.uname.c_str(), it.vname.c_str(), it.route.c_str(), it.w);
        }
        printf("%58s\n", pretty.substr(0, 5).c_str());
        printf("%47s%11d\n", "Total", cost);

    };

    for (auto [From, To] : dd) {
        vector<int> dist(id + 5, mod);
        vector<int> par(id + 5, -1);
        priority_queue<pii> q;
        q.push({0, From});
        cache = vector<edge>(id + 5);
        dist[From] = 0;
        par[From] = From;
        while (q.size()) {
            auto [cost, u] = q.top();
            q.pop();
            cost = -cost;
            if (dist[u] < cost) continue;
            for (auto it : g[u]) {
                if (dist[it.v] > dist[u] + it.w) {
                    dist[it.v] = dist[u] + it.w;
                    q.push({-dist[it.v], it.v});
                    par[it.v] = u;
                    cache[it.v] = it;
                }
            }
        }
        Report(From, To, dist[To], par);
    }
}

signed main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    // cin >> t;
    int cs = 1;
    while (t--) {
        //cout << "Case " << cs++ << ":" << " ";
        solve();
    }
}
