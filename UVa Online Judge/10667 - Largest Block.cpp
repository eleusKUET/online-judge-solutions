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

int n;

void solve()
{
    cin >> n;

    int b;
    cin >> b;
    vector<vector<int>> a(n + 4, vi(n + 5)), pre = a;

    for (int i = 1; i <= b; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        for (int j = r1; j <= r2; j++) {
            a[j][c1]++;
            a[j][c2 + 1]--;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] += a[i][j - 1];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = !a[i][j];
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + a[i][j];
        }
    }

    auto getsum = [&](int r1, int c1, int r2, int c2) {
        return pre[r2][c2] - pre[r2][c1 - 1] - pre[r1 - 1][c2]  + pre[r1 - 1][c1 - 1];
    };

    int ans = 0;

    for (int h = 1; h <= n; h++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (j + h - 1 > n) break;
                int r1 = i;
                int c1 = j;
                int c2 = j + h - 1;
                if (getsum(r1, c1, r1, c2) != h) continue;
                int r2 = i;

                int lo = i;
                int hi = n;

                while (lo <= hi) {
                    int mid = (lo + hi) / 2;

                    int sum = getsum(r1, c1, mid, c2);
                    if (sum == (mid - r1 + 1) * (c2 - c1 + 1)) {
                        lo = mid + 1;
                        r2 = mid;
                    }
                    else {
                        hi = mid - 1;
                    }
                }
                ans = max(ans, (r2 - r1 + 1) * (c2 - c1 + 1));
            }
        }
    }

    cout << ans << "\n";
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
