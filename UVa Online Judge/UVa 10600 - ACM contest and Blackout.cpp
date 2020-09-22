#include<bits/stdc++.h>
using namespace std;
#define U first.first
#define V first.second
#define W second
#define ii pair<int,int>

const int N = 105;
int par[N];
int sz[N];
vector<pair<ii,int>> e;
queue<int> q;
int n, m;

int Find(int u)
{
    if (par[u] == u) return u;
    return par[u] = Find(par[u]);
}

bool Union(int u, int v)
{
    int a = Find(u);
    int b = Find(v);
    if (a == b) return true;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
    return false;
}

bool cmp(pair<ii,int> a, pair<ii,int> b)
{
    return a.W < b.W;
}

int Cost(int skip)
{
    int cost = 0;
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
    }
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        if (skip == i) continue;
        if (!Union(e[i].U, e[i].V)) {
            cost += e[i].W;
            if (skip == -1) q.push(i);
            cnt++;
        }
    }
    if (cnt != n -1) cost = INT_MAX;
    return cost;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        int a, b, c;
        for (int i = 1; i <= m; i++) {
            cin >> a >> b >> c;
            e.push_back({{a, b}, c});
        }
        sort(e.begin(), e.end(), cmp);
        int f = Cost(-1);
        int s = INT_MAX;
        while (!q.empty()) {
            s = min(s, Cost(q.front()));
            q.pop();
        }
        cout << f << " " << s << "\n";
        e.clear();
    }
}
