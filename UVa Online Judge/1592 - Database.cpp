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

const int mod = 1e9 + 7;

const int N = 1e5;


void solve()
{
    int n, m;
    char t[100];
    
    while (gets(t)) {
        char *tk = strtok(t, " ");
        n = atoi(tk);
        tk = strtok(NULL, " ");
        m = atoi(tk);
        // if (n == 0) break;
        
        string s[n][m];
        for (int i = 0; i < n; i++) {
            gets(t);
            tk = strtok(t, ",");
            for (int j = 0; j < m; j++) {
                s[i][j] = string(tk);
                tk = strtok(NULL, ",");
            }
        }
        map<pii, map<pair<string, string>,vi>> rep;
        for (int j = 0; j < m; j++) {
            for (int k = j + 1; k < m; k++) {
                for (int i = 0; i < n; i++) {
                    rep[{j, k}][{s[i][j], s[i][k]}].pb(i);
                }
            }
        }
        int r1, r2, c1, c2;
        r1 = r2 = c1 = c2 = -1;
        
        for (auto it : rep) {
            for (auto it2 : it.s) {
                if (it2.s.size() > 1) {
                    r1 = it2.s.front() + 1;
                    r2 = it2.s.back() + 1;
                    c1 = it.f.f + 1;
                    c2 = it.f.s + 1;
                    break;
                }
            }
            if (r1 != -1) break;
        }
        if (r1 == -1){
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
            cout << r1 << " " << r2 << "\n";
            cout << c1 << " " << c2 << "\n";
        } 
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
