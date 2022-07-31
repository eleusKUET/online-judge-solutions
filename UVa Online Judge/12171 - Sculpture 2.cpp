// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T> using Tree = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

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

template<typename T_vector>
void output_vector(T_vector a, int lo = -1, int hi = -1, bool line = false)
{
    if (lo == -1) lo = 0;
    if (hi == -1) hi = a.size();
    for (int i = lo; i < hi; i++) {
        cout << a[i] << (line ? "\n" : " ");
    }
    cout << "\n";
}

#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define f first
#define s second
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define vpi vector<pair<int,int>>
#define ll long long
#define pll pair<long long,long long>
#define vpl vector<pair<long long,long long>>
#define vll vector<long long>
#define lb lower_bound
#define ub upper_bound
#define Checkbit(a,i) (((a)>>(i))&1)
#define Setbit(a,i) ((a)^=1LL<<(i))


const int mod = 1e9 + 7;

const int N = 100;

bool mark[N + 5][N + 5][N + 5];
bool unmark[N + 5][N + 5][N + 5];
int n;
int x[105], y[105], z[105];
int rx[1005], ry[1005], rz[1005];
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

void solve()
{
    cin >> n;
    vector<array<int,6>> v(n);
    
    memset(mark, 0, sizeof mark);
    memset(unmark, 0, sizeof unmark);
    memset(x, 0, sizeof x);
    memset(y, 0, sizeof y);
    memset(z, 0, sizeof z);
    memset(rx, 0, sizeof rx);
    memset(ry, 0, sizeof ry);
    memset(rz, 0, sizeof rz);
     
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> v[i][j];
        }
        v[i][3] += v[i][0];
        v[i][4] += v[i][1];
        v[i][5] += v[i][2];
        rx[v[i][0]] = 1;
        rx[v[i][3]] = 1;
        ry[v[i][1]] = 1;
        ry[v[i][4]] = 1;
        rz[v[i][2]] = 1;
        rz[v[i][5]] = 1;
    }
    int id = 1;
    for (int i = 1; i <= 1000; i++) {
        if (rx[i]) rx[i] = id++, x[rx[i]] = i;
    }
    x[id] = 1100;
    int lx = id + 1;
    id = 1;
    
    for (int i = 1; i <= 1000; i++) {
        if (ry[i]) ry[i] = id++, y[ry[i]] = i;
    }
    y[id] = 1100;
    int ly = id + 1;
    
    id = 1;
    for (int i = 1; i <= 1000; i++) {
        if (rz[i]) rz[i] = id++, z[rz[i]] = i;
    }
    z[id] = 1100;
    int lz = id + 1;
    
    for (int i = 0; i < n; i++) {
        v[i][0] = rx[v[i][0]];
        v[i][1] = ry[v[i][1]];
        v[i][2] = rz[v[i][2]];
        v[i][3] = rx[v[i][3]];
        v[i][4] = ry[v[i][4]];
        v[i][5] = rz[v[i][5]];
        
        for (int X = v[i][0]; X < v[i][3]; X++) {
            for (int Y = v[i][1]; Y < v[i][4]; Y++) {
                for (int Z = v[i][2]; Z < v[i][5]; Z++) {
                    mark[X][Y][Z] = true;
                }
            }
        }
    }
    
    
    int water = 1100*1100*1100;
    int area = 0;
    queue<array<int,3>> q;
    
    q.push({0, 0, 0});
    unmark[0][0][0] = true;
    
    while (!q.empty()) {
        auto [u, v, w] = q.front();
        q.pop();
        
        water -= (x[u + 1] - x[u]) * (y[v + 1] - y[v]) * (z[w + 1] - z[w]);
        
        for (int i = 0; i < 6; i++) {
            int a = u + dx[i];
            int b = v + dy[i];
            int c = w + dz[i];
            if (a < 0 || b < 0 || c < 0 || a >= lx - 1 || b >= ly - 1 || c >= lz - 1) {
                continue;
            }
            if (mark[a][b][c]) {
                if (dx[i]) {
                    area += (y[v + 1] - y[v]) * (z[w + 1] - z[w]);
                }
                else if (dy[i]) {
                    area += (x[u + 1] - x[u]) * (z[w + 1] - z[w]);
                }
                else {
                    area += (x[u + 1] - x[u]) * (y[v + 1] - y[v]);
                }
            }
            else if (!unmark[a][b][c]) {
                unmark[a][b][c] = true;
                q.push({a, b, c});
            }
        }
    }
    cout << area << " " << water << "\n";
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
        //cout << "Case " << cs++ << ":" << " ";
        solve();
    }
}
