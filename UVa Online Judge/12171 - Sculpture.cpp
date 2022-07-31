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

const int N = 2e5;

struct cell
{
    int x, y, z;
    cell(int a = 0, int b = 0, int c = 0) {x = a, y = b, z = c;}
};

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

void elim(vi &a)
{
    a.pb(0);
    a.pb(1100);
    sort(all(a));
    
    unique(all(a));
}

void solve()
{
    int n;
    cin >> n;
    
    int x0[n], x1[n], y0[n], y1[n], z0[n], z1[n];
    vi xs, ys, zs;
    
    for (int i = 0; i < n; i++) {
        cin >> x0[i] >> y0[i] >> z0[i] >> x1[i] >> y1[i] >> z1[i];
        x1[i] += x0[i];
        z1[i] += z0[i];
        y1[i] += y0[i];
        
        xs.pb(x0[i]);
        xs.pb(x1[i]);
        ys.pb(y0[i]);
        ys.pb(y1[i]);
        zs.pb(z0[i]);
        zs.pb(z1[i]);
    }
    elim(xs);
    elim(ys);
    elim(zs);
    
    int nx = xs.size();
    int ny = ys.size();
    int nz = zs.size();
    
    auto boxes = vector<vector<vector<bool>>>(nx, vector<vector<bool>>(ny, vector<bool>(nz, false)));
    auto vis = vector<vector<vector<bool>>>(nx, vector<vector<bool>>(ny, vector<bool>(nz, false)));
    
    for (int i = 0; i < n; i++) {
        
        int xpos0 = lb(all(xs), x0[i]) - xs.begin();
        int xpos1 = lb(all(xs), x1[i]) - xs.begin();
        int ypos0 = lb(all(ys), y0[i]) - ys.begin();
        int ypos1 = lb(all(ys), y1[i]) - ys.begin();
        int zpos0 = lb(all(zs), z0[i]) - zs.begin();
        int zpos1 = lb(all(zs), z1[i]) - zs.begin();
        
        for (int x = xpos0; x < xpos1; x++) {
            for (int y = ypos0; y < ypos1; y++) {
                for (int z = zpos0; z < zpos1; z++) {
                    boxes[x][y][z] = true;
                }
            }
        }
    }
    
    queue<cell> q;
    q.push(cell(0, 0, 0));
    vis[0][0][0] = true;
    
    int vol = 1100 * 1100 * 1100;
    int area = 0;
    
    while (q.size()) {
        cell cur = q.front();
        q.pop();
        
        int lx = (xs[cur.x + 1] - xs[cur.x]),
            ly = (ys[cur.y + 1] - ys[cur.y]),
            lz = (zs[cur.z + 1] - zs[cur.z]);
            
        vol -= lx * ly * lz;
        
        for (int i = 0; i < 6; i++) {
            cell next(cur.x + dx[i], cur.y + dy[i], cur.z + dz[i]);
            if (next.x < 0 || next.y < 0 || next.z < 0 || next.x >= nx - 1 || next.y >= ny - 1 || next.z >= nz - 1) {
                continue;
            }
            if (boxes[next.x][next.y][next.z]) {
                if (dx[i]) {
                    area += ly * lz;
                }
                else if (dy[i]) {
                    area += lz * lx;
                }
                else {
                    area += lx * ly;
                }
            }
            else if (vis[next.x][next.y][next.z] == false) {
                vis[next.x][next.y][next.z] = true;
                q.push(next);
            }
        }
    }
    
    cout << area << " " << vol << "\n";
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
