//Author: Eleus Ahammad
#include<bits/stdc++.h>
using namespace std;
//#include "debugger.cpp"

string x, y;

const int N = 1e4 + 5;
vector<int> g[N];
vector<int> h[N];

void formTree(vector<int> g[], string path);
string dfs(vector<int> g[], int u, int p);

bool comp(string a, string b)
{
    if (a.size() != b.size()) return a.size() < b.size();
    return a < b;
}

void solve()
{
    cin >> x >> y;
    formTree(g, x);
    formTree(h, y);
    x = dfs(g, 1, -1);
    y = dfs(h, 1, -1);
    if (x == y) puts("same");
    else puts("different");
    for (int i = 0; i < N; i++) {
        g[i].clear();
        h[i].clear();
    }
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

void formTree(vector<int> g[], string path)
{
    int cur = 1;
    stack<int> s;
    s.push(1);
    for (int i = 0; i < path.size(); i++) {
        if (path[i] == '0') {
            int u = s.top();
            int v = ++cur;
            g[u].push_back(v);
            g[v].push_back(u);
            s.push(v);
        }
        else s.pop();
    }
}

string dfs(vector<int> g[], int u, int p)
{
    vector<string> a;
    for (auto v : g[u]) {
        if (v != p) {
            a.push_back(dfs(g, v, u));
        }
    }
    if (!a.empty()) sort(a.begin(), a.end(), comp);
    string ret = "(";
    for (auto x : a) ret += x;
    return ret + ")";
}
