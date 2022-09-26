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
#include <bitset>
#include <sstream>
#include <numeric>

#ifdef __LOCAL__
#include "debug.h"
#else
#define debug(...)
#endif

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T> using Tree = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

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
#define inf 1e18

const int mod = 1e9 + 7;

const int N = 15000;

double c;
int n, m, k;
string nm[10];
int sz[10];
int limit[10];
double prices[10][105];

map<vi, int> statesId;
vector<vector<int>> states;


void backtrack(vi mask, int idx, int sum)
{
   
    if (idx == n) {
        int id = statesId.size();
        statesId[mask] = id;
        states.pb(mask);
        return;
    }
    
    for (int i = 0; i <= limit[idx] && i + sum <= k; i++) {
        mask[idx] = i;
        backtrack(mask, idx + 1, sum + i);
    }
}

double dp[105][N];
pii from[105][N];

int buy[N][10];
int sell[N][10];

void DAG()
{
    for (int i = 0; i < states.size(); i++) {
        int tot = 0;
        vi &u = states[i];
        for (int j = 0; j < n; j++) {
            tot += u[j];
        }
        for (int j = 0; j < n; j++) {
            buy[i][j] = sell[i][j] = -1;
            if (u[j] < limit[j] && tot < k) {
                vi v = u;
                v[j]++;
                buy[i][j] = statesId[v];
            }
            if (u[j] > 0) {
                vi v = u;
                v[j]--;
                sell[i][j] = statesId[v];
            }
        }
    }
}

void update(int day, int u, int v, double val, int data)
{
    if (val > dp[day + 1][v]) {
        dp[day + 1][v] = val;
        from[day + 1][v] = {u, data};
    }
}

int cs;

void solve()
{
    
    while (cin >> c >> m >> n >> k) {
        if (cs++) {
            cout << "\n";
        }
        for (int i = 0; i < n; i++) {
            cin >> nm[i] >> sz[i] >> limit[i];
            
            for (int j = 0; j < m; j++) {
                cin >> prices[i][j];
                prices[i][j] *= sz[i];
            }
        }
        vi mask(n);
        
        backtrack(mask, 0, 0);
        assert(states.size() < N);
        
        DAG();
        
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j < states.size(); j++) {
                dp[i][j] = -inf;
            }
        }
        
        dp[0][0] = c;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < states.size(); j++){
                auto val = dp[i][j];
                if (val < 0) continue;
                update(i, j, j, val, 0);
                for(int k = 0; k < n; k++) {
                    if (buy[j][k] >= 0 && val >= prices[k][i] - eps) {
                        update(i, j, buy[j][k], val - prices[k][i], k + 1);
                    }
                    if (sell[j][k] >= 0) {
                        update(i, j, sell[j][k], val + prices[k][i], - k - 1);
                    }
                }
            }
        }
        
        cout << setprecision(2) << fixed << dp[m][0] << "\n";
        vector<int> ret;
        
        for (int i = m, j = 0; i > 0; i--) {
            ret.pb(from[i][j].second);
            j = from[i][j].first;
        }

        
        for(int i = (int) ret.size() - 1; i >= 0; i--) {
            if (ret[i] > 0) {
                cout << "BUY " << nm[ret[i] - 1] << "\n";
            }
            else if (ret[i] < 0) {
                cout << "SELL " << nm[-ret[i] - 1] << "\n";
            }
            else {
                cout <<"HOLD\n";
            }
        }
        
        states.clear();
        statesId.clear();
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
