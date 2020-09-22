#include<bits/stdc++.h>
using namespace std;
using ii = pair<int,int>;
#define U first.first
#define V first.second
#define W second
#define F first

const int N = 505;
int par[N];
int sz[N];
vector<pair<ii,int>> e;
int s, p;

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

bool comp(pair<ii,int> a, pair<ii,int> b)
{
    return a.W < b.W;
}

int kruskal(int x)
{
    int cnt = p;
    for (int i = 1; i <= p; i++) {
        par[i] = i;
        sz[i] = 1;
    }
    for (int i = 0; i < e.size(); i++) {
        if (e[i].W > x) break;
        if (!Union(e[i].U, e[i].V)) {
            cnt--;
        }
    }
    return cnt;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        cin >> s >> p;
        vector<ii> cor;
        int u, v;
        for (int i = 1; i <= p; i++) {
            cin >> u >> v;
            cor.push_back({u, v});
        }
        for (int i = 0; i < p; i++) {
            for (int j = i + 1; j < p; j++) {
                int dist = (cor[i].F - cor[j].F) * (cor[i].F - cor[j].F) + (cor[i].W - cor[j].W) * (cor[i].W - cor[j].W);
                e.push_back({{i + 1, j + 1}, dist});
            }
        }
        sort(e.begin(), e.end(), comp);
        int lo = 0, hi = 1e7;
        int ans;
        while (lo <= hi) {
            int mid = lo + hi >> 1;
            if (kruskal(mid) <= s) {
                hi = mid - 1;
                ans = mid;
            }
            else lo = mid + 1;
        }
        cout << setprecision(2) << fixed << sqrt(ans) << "\n";
        e.clear();
    }
}
