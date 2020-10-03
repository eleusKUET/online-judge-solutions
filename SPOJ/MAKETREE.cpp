#include<bits/stdc++.h>
using namespace std;
 
const int N = 100005;
vector<int> g[N];
int vis[N];
vector<int> ans;
 
void dfs(int u)
{
    vis[u] = 1;
    for (auto v : g[u]) {
        if (vis[v]) continue;
        dfs(v);
    }
    ans.push_back(u);
}
 
int main()
{
    ios::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    int u, w;
    for (int i = 1; i <= k; i++) {
        cin >> w;
        for (int j = 1; j <= w; j++) {
            cin >> u;
            g[i].push_back(u);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        dfs(i);
    }
    reverse(ans.begin(), ans.end());
    vector<int> fi(n + 1);
    fi[ans[0]] = 0;
    for (int i = 1; i < ans.size(); i++) {
        fi[ans[i]] = ans[i - 1];
    }
    for (int i = 1; i <= n; i++)
        cout << fi[i] << "\n";
}
