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

// #define ONLINE_JUDGE
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


vector<string> tokenizer(string cmd)
{
    stringstream tk(cmd);
    vector<string> res;
    while (tk >> cmd) {
        res.pb(cmd);
    }
    return res;
}


void solve()
{
    int programs;
    int var, print, lock, unlock, end, t;
    cin >> programs >> var >> print >> lock >> unlock >> end >> t;
    vector<string> vars(26, "0");
    
    deque<string> q[programs + 1];
    
    string dummy;
    getline(cin, dummy);
    
    for (int i = 1; i <= programs; i++) {
        string cmd;
        while (getline(cin, cmd)) {
            q[i].pb(cmd);
            vector<string> res = tokenizer(cmd);
            if (res[0] == "end") {
                break;
            }
        }
    }
    
    deque<int> blocked, run;
    for(int i = 1; i <= programs; i++) {
        run.pb(i);
    }
    bool block = false;
    
    while (!run.empty()) {
        int id = run.front();
        run.pop_front();
        
        int tm = 0;
        bool is_blocked = false;
        
        while (!q[id].empty() && tm < t) {
            string cmd = q[id].front();
            q[id].pop_front();
            
            vector<string> res = tokenizer(cmd);
            
            if (res[0].size() == 1) {
                vars[res[0][0] - 'a'] = res[2];
                tm += var;

            }
            else if (res[0] == "print") {
                cout << id << ": " << vars[res[1][0] - 'a'] << "\n";
                tm += print;
            }
            else if (res[0] == "lock") {
                if (block) {
                    q[id].push_front(cmd);
                    blocked.pb(id);
                    is_blocked = true;
                    break;
                }
                tm += lock;
                block = true;
            }
            else if (res[0] == "unlock") {
                tm += unlock;
                block = false;
                if (!blocked.empty()) {
                    run.push_front(blocked.front());
                    blocked.pop_front();
                }
            }
            else {
                tm += end;
            }
        }
        if (!is_blocked && q[id].size()) {
            run.push_back(id);
        }
    }
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
        if (t) cout << "\n";
    }
}
