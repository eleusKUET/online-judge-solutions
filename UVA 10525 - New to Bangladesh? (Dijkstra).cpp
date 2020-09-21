#include "bits/stdc++.h"
using namespace std;
#define int long long
#define INF INT_MAX

struct edge {
    int node, cost, _time; edge(){} edge(int a, int b, int c) {
        node = a; cost = b; _time = c;
    }
};

vector<vector<edge>> g;

void dijkstra(int start, int stop)
{
    int sz = g.size();
    vector<int> d(sz, INF), t(sz, INF);

    auto cmp = [] (edge a, edge b) {
        if (a._time == b._time) return a.cost > b.cost;
        return a._time > b._time;
    };
    priority_queue<edge,vector<edge>,decltype(cmp)> q(cmp);
    q.push(edge(start, 0, 0));
    d[start] = t[start] = 0;

    while (!q.empty()) {
        edge u = q.top();
        q.pop();
        for (edge v : g[u.node]) {
            if (t[u.node] + v._time < t[v.node]) {
                t[v.node] = t[u.node] + v._time;
                d[v.node] = d[u.node] + v.cost;
                q.push(edge(v.node, d[v.node], t[v.node]));
            }
            else if (t[u.node] + v._time == t[v.node] && d[u.node] + v.cost < d[v.node]) {
                d[v.node] = d[u.node] + v.cost;
                q.push(edge(v.node, d[v.node], t[v.node]));
            }
        }
    }
    if (d[start] != INF && t[stop] != INF) {
        printf("Distance and time to reach destination is %lld & %lld.\n", d[stop], t[stop]);
    }
    else {
        puts("No Path.");
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    g.resize(n);
    for (int i = 1; i <= m; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--; b--;
        g[a].push_back(edge(b, d, c));
        g[b].push_back(edge(a, d, c));
    }
    int q; cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b; a--; b--;
        dijkstra(a, b);
    }
    g.clear();
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        solve();
        if (t) cout << "\n";
    }
}
