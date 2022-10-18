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
#include <functional>

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(...)
#endif

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T> using oset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template <class K,class V> using omap = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

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

int a[1000][1000];

void solve()
{
    int k;
    while (cin >> k) {
        for (int i = 0; i < k; i++) {
            cin >> a[0][i];
        }
        sort(a[0], a[0] + k);
        for (int i = 1; i < k; i++) {
            for (int j = 0; j < k; j++) {
                cin >> a[i][j];
            }
            sort(a[i], a[i] + k);
            multiset<pii> s;
            for (int j = 0; j < k; j++) {
                s.insert({a[i][j] + a[i - 1][0], 0});
            }
            for (int j = 0; j < k; j++) {
                auto [val, pos] = *s.begin();
                s.erase(s.begin());
                a[i][j] = val;
                s.insert({val - a[i - 1][pos] + a[i - 1][pos + 1], pos + 1});
            }

        }
        for (int i = 0; i < k; i++) {
            cout << a[k - 1][i] << " \n"[i + 1 == k];
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
