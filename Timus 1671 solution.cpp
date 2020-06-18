//Timus 1671
//Author: Eleus Ahammad
//CSE, KUET


#include<bits/stdc++.h>
using namespace std;
using ii = pair<int,int>;

const int N = 100005;
int parent[N], sz[N];

int Find(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = Find(parent[v]);
}

void Union(int u, int v)
{
    int a = Find(u);
    int b = Find(v);
    if (a == b) return;
    if (sz[a] < sz[b]) {
        swap(a, b);
    }
    parent[b] = a;
    sz[a] += sz[b];
}

int main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;

    vector<ii> g;
    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        sz[u] = sz[v] = 1;
        parent[u] = u;
        parent[v] = v;
        g.push_back({u, v});
    }

    int q;
    cin >> q;
    vector<int> id(q);
    bool vis[m];
    memset(vis, 0, sizeof vis);

    for (auto &it:id) {
        cin >> it;
        it--;
        vis[it] = true;
    }
    int cnt = n;
    for (int i = 0; i < m; i++) {
        if (vis[i]) continue;
        u = g[i].first;
        v = g[i].second;
        cnt -= (Find(u) != Find(v));
        Union(u, v);
    }
    deque<int> ans;
    for (int i = q - 1; i >= 0; i--) {
        ans.push_front(cnt);
        u = g[id[i]].first;
        v = g[id[i]].second;
        cnt -= (Find(u) != Find(v));
        Union(u, v);
    }
    for (int i = 0; i < ans.size(); i++) {
        if (i > 0) cout << " ";
        cout << ans[i];
    }
    cout << "\n";
}
