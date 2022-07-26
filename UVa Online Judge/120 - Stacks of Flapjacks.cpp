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
#include <sstream>
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
        cout << a[i] << ((i + 1 >= hi) ? "\n" : " ");
    }
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

int find(deque<int> &a, int key)
{
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == key) return i;
    }
    return -1;
}

void solve()
{
    string nums;
    while (getline(cin, nums)) {
        if (nums.size() == 0) break;
        stringstream sin(nums);
        
        deque<int> a;
        while (sin >> nums) {
            a.pb(atoi(nums.c_str()));
        }
        
        deque<int> b = a, tmp = a;
        sort(all(b));
        vi ans;
        for (int i = b.size() - 1; i >= 0; i--) {
            if (b[i] != a[i]) {
                int pos = find(a, b[i]);

                if (pos > 0) {
                    reverse(a.begin(), a.begin() + 1 + pos);
                    ans.pb(a.size() - pos);
                }
                ans.pb(a.size() - i);
                reverse(a.begin(), a.begin() + 1 + i);
            }
        }
        // debug(b, a);
        output_vector<deque<int>>(tmp);
        ans.pb(0);
        output_vector<vi>(ans);
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
