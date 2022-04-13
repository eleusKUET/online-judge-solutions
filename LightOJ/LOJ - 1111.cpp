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
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define ll long long
#define Checkbit(a,i) (((a)>>(i))&1)
#define Setbit(a,i) ((a)^=1LL<<(i))
#define space " "
#define nline "\n"

const int mod = 1e9 + 7;

const int N = 1000;

int n, m, k;
vi g[N];
vi city(N);


void solve()
{

    cin >> k >> n >> m;
    for (int i = 0; i < n; i++) {
        g[i].clear();
        city[i] = 0;
    }
    for (int i = 0; i < k; i++) {
        cin >> city[i];
        city[i]--;
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].pb(v);
    }

    vi sz(n);
    for (int i = 0; i < k; i++) {
        vi vis(n);
        queue<int> q;
        q.push(city[i]);
        vis[city[i]]++;
        sz[city[i]]++;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto v : g[u]) {
                if (!vis[v]) {
                    q.push(v);
                    vis[v]++;
                    sz[v]++;
                }
            }
        }

    }
    int cnt = 0;
    for (int j = 0; j < n; j++) {
        // debug(sz[j], j);
        cnt += sz[j] == k;
    }

    cout << cnt << nline;
}

signed main()
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    int cs = 1;
    while (t--) {
        cout << "Case " << cs++ << ":" << " ";
        solve();
    }
}
