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

vi prime[N + 1];

void solve()
{
    int t, s;
    cin >> s >> t;
    vi vis(t + 1);
    queue<pii> q;
    q.push({s, 0});
    vis[s]++;

    while(!q.empty()) {
        auto [u, cnt] = q.front();
        q.pop();

        if (u == t) {
            cout << cnt << nline;
            return;
        }

        for (auto v: prime[u]) {
            if (v + u <= t && !vis[u + v]) {
                q.push({u + v, cnt + 1});
                vis[u + v]++;
            }
        }
    }
    cout << -1 << nline;
}

signed main()
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 2; i <= N; i++) {
        int h = i;
        for (int j = 2; j * j <= h; j++) {
            bool ok = false;
            while (h%j == 0) {
                ok = true;
                h /= j;
            }
            if (ok) {
                prime[i].pb(j);
            }
        }
        if (h != i && h > 1) prime[i].pb(h);
        // for (auto it : prime[i]) {
        //     cout << it << space;
        // }
        // cout << nline;
    }

    int t = 1;
    cin >> t;
    int cs = 1;
    while (t--) {
        cout << "Case " << cs++ << ":" << " ";
        solve();
    }
}
