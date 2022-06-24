// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")

#include "bits/stdc++.h"
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

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
#define vpi vector<pii>
#define ll long long
#define pll pair<ll,ll>
#define vpl vector<pll>
#define vll vector<ll>
#define extended_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define Checkbit(a,i) (((a)>>(i))&1)
#define Setbit(a,i) ((a)^=1LL<<(i))


const int mod = 1e9 + 7;

const int N = 2e4;

int par[N];
int sz[N];

int Find(int u)
{
    if (par[u] == u) return u;
    return par[u] = Find(par[u]);
}

bool Union(int u, int v)
{
    int a = Find(u);
    int b = Find(v);
    if (a == b) return false;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    par[b] = a;
    return true;
}

void solve()
{
    int n;
    cin >> n;
    for(int i = 0; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
    }
    int adj[n][n];
    
    vector<pair<pii,int>> edge, ans;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            string h;
            cin >> h;
            if(h.back() == ',') h.pop_back();
            adj[i][j] = atoi(h.c_str());
            if (adj[i][j] && i < j) {
                edge.pb({{i, j}, adj[i][j]});
            }
        }
    }
    sort(all(edge), [](pair<pii,int> a, pair<pii, int> b){
        if (a.s == b.s) {
            return a.f < b.f;
        }
        return a.s < b.s; 
    });
    
    for (int i = 0; i < edge.size(); i++) {
        if(Union(edge[i].f.f, edge[i].f.s)) {
            ans.pb(edge[i]);
        }
    }
    
    for (auto [nd, w] : ans) {
        printf("%c-%c %d\n", 'A' + nd.f, 'A' + nd.s, w);
    }
}

signed main()
{
    // freopen("input.txt", "r", stdin);
    
    int t = 1;
    cin >> t;
    int cs = 1;
    while (t--) {
        cout << "Case " << cs++ << ":" << "\n";
        solve();
    }
}
