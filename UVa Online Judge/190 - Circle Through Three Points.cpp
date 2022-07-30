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

#define eps 1e-9

const int mod = 1e9 + 7;

const int N = 2e5;


double eqn[3][3];
double res[3];

int gauss()
{
    int n = 3;
    
    for (int i = 0; i < n; i++) {
        int id = i;
        
        for (int j = i + 1; j < n; j++) {
            if (abs(eqn[j][i]) > abs(eqn[id][i])) {
                id = j;
            }
        }
        
        if (id != i){
            for (int j = 0; j < n; j++) {
                swap(eqn[i][j], eqn[id][j]);
            }
            swap(res[i], res[id]);
        }
        
        if (abs(eqn[id][i]) < eps) {
            continue;
        }
        
        for (int j = 0; j < n; j++) {
            if (j != i) {
                double factor = eqn[j][i] / eqn[i][i];
                for (int k = i; k < n; k++) {
                    eqn[j][k] -= factor * eqn[i][k];
                }
                res[j] -= factor * res[i];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        double sum = 0;
        for (int j = 0; j < n; j++) {
            sum += eqn[i][j];
        }
        if (abs(sum) < eps && abs(res[i]) > eps) {
            return 0;
        }
        if (abs(sum) < eps && abs(res[i]) < eps) return 2;
    }
    return 1;
}

string sign(double a, bool alter = true)
{
    if (abs(a) < eps) {
        return alter? " - " : " + ";
    }
    if (a < 0) return alter? " + " : " - ";
    else return alter? " - " : " + ";
}

void solve()
{
    double x1, y1, x2, y2, x3, y3;
        
    while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3) {
    
        eqn[0][0] = x1; eqn[0][1] = y1; eqn[0][2] = -1; res[0] = - x1 * x1 - y1 * y1;
        eqn[1][0] = x2; eqn[1][1] = y2; eqn[1][2] = -1; res[1] = - x2 * x2 - y2 * y2;
        eqn[2][0] = x3; eqn[2][1] = y3; eqn[2][2] = -1; res[2] = - x3 * x3 - y3 * y3;
        
        gauss();
        
        double c = res[0];
        double d = res[1];
        double e = res[2];
        if (abs(eqn[0][0]) > eps) c /= eqn[0][0];
        if (abs(eqn[1][1]) > eps) d /= eqn[1][1];
        if (abs(eqn[2][2]) > eps) e /= eqn[2][2];

        double h = - c / 2, k = - d / 2, r = sqrt(c * c / 4.0 + d * d / 4.0 + e);
        
        // debug(h, k, r);
        // debug(c, d, e);
        
        cout << setprecision(3) << fixed;
        cout << "(x" << sign(h) << abs(h) << ")^2 + (y" << sign(k) << abs(k) << ")^2 = " << r << "^2\n";
        cout << "x^2 + y^2" << sign(c, 0) << abs(c) << "x" << sign(d, 0) << abs(d) << "y" << sign(e) << abs(e) << " = 0\n\n";
    }
}

signed main()
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    int cs = 1;
    while (t--) {
        //cout << "Case " << cs++ << ":" << " ";
        solve();
    }
}
