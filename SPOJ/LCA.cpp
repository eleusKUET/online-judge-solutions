#include "bits/stdc++.h"
using namespace std;
//#define ONLINE_JUDGE
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define f first
#define s second

vector<vector<int>> g, f;
vector<int> depth;
const int LOG = 20;
vector<vector<int>> up;
int n;

void dfs(int u)
{
    for (auto v : g[u]) {
        depth[v] = depth[u] + 1;
        up[v][0] = u;
        for (int i = 1; i < LOG; i++) {
            up[v][i] = up[up[v][i - 1]][i - 1];
        }
        dfs(v);
    }
}

int lca(int u, int v)
{
    if (depth[u] < depth[v]) swap(u, v);
    int k = depth[u] - depth[v];
    for (int i = LOG - 1; i >= 0; i--) {
        if ((k >> i) & 1) {
            u = up[u][i];
        }
    }
    if (v == u) return u;
    for (int i = LOG - 1; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

void solve()
{
    cin >> n;
    g = vector<vector<int>>(n, vector<int>());
    f = vector<vector<int>>(n, vector<int>());
    up = vector<vector<int>>(n, vector<int>(LOG));
    depth = vector<int>(n);

    //debug(n);

    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        for (int j = 0; j < l; j++) {
            int h;
            cin >> h;
            h--;
            g[i].push_back(h);
            f[h].push_back(i);
        }
        //debug("ok");
    }
    int root;
    for (int i = 0; i < n; i++) {
        if (!f.empty()) {
            root = i;
            break;
        }
    }
    //debug(root);

    dfs(root);
    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        cout << 1 + lca(u, v) << "\n";
    }

    g.clear();
    depth.clear();
    up.clear();
    f.clear();
}

signed main()
{
    //freopen("input.txt", "r", stdin);

    int t;
    cin >> t;
    int cs = 1;
    while (t--) {
        printf("Case %d:\n", cs++);
        solve();
    }
}
