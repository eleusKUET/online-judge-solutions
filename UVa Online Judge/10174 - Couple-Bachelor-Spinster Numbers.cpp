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

ll f(ll n)
{
    return n / 4 + (n + 1) / 2;
}

void solve()
{
    string input;
    while (getline(cin, input)) {
        stringstream ss(input);
        vector<ll> a;
        while (ss >> input) {
            a.pb(atoll(input.c_str()));
        }
        if (a.empty()) break;
        if(a.size() == 1) {
            ll n = a.front();
            if (n%4 == 0 || n % 2) {
                if (n == 0) {
                    cout << "0 0\n";
                }
                else if (n > 0) {
                    if (n%2 == 0) {
                        cout << (2 + n / 2) / 2 << " " << (n / 2 - 2) / 2 << "\n";
                    }
                    else {
                        cout << (n + 1) / 2 << " " << (n - 1) / 2 << "\n";
                    }
                }
                else {
                    n = abs(n);
                    if (n%2 == 0) {
                        cout << (n / 2 - 2) / 2 << " " << (n / 2 + 2) / 2 << "\n";
                    }
                    else {
                        cout << (n - 1) / 2 << " " << (n + 1) / 2 << "\n";
                    }
                }
            }
            else {
                cout << "Bachelor Number.\n";
            }
        }
        else {
            ll l = a.front();
            ll r = a.back();
            ll len = r - l + 1;
            if (r < 0) {
                cout << len - (f(abs(l)) - f(abs(r + 1))) << "\n";
            }
            else if (l > 0) {
                cout << len - (f(r) - f(l - 1)) << "\n";
            }
            else {
                cout << len - (f(r) + f(abs(l)) + 1) << "\n";
            }
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
