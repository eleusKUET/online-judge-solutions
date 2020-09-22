//UVA 10461
//Author: Eleus Ahammad
//CSE, KUET
#include<bits/stdc++.h>
using namespace std;

const int N = 1000;
vector<int> g[N];
vector<int> h[N];
int du[N];

int bfs(int u, vector<int> g[])
{
    set<int> used;
    used.insert(u);
    queue<int> q;
    q.push(u);
    int sum = du[u];
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (auto v : g[u]) {
            if (used.count(v)) continue;
            used.insert(v);
            q.push(v);
            sum += du[v];
        }
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(0);
    int n, m;
    int cs = 1;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        int total = 0;
        for (int i = 1; i <= n; i++) {
            cin >> du[i];
            total += du[i];
        }
        int u, v;
        for (int i = 1; i <= m; i++) {
            cin >> u >> v;
            g[u].push_back(v);
            h[v].push_back(u);
        }
        int q;
        cin >> q;
        cout << "Case #" << cs++ << ":\n";
        while (q--) {
            cin >> u;
            int sum = bfs(u, h) - du[u];
            cout << (total - sum) - bfs(u, g) << "\n";
        }
        for (int i = 1; i <= n; i++) {
            du[i] = 0;
            g[i].clear();
            h[i].clear();
        }
        cout << "\n";
    }
}
