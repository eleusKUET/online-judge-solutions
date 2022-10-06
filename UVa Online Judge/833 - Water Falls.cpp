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
#define int long long 
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

const int N = 1e5;

using ppp = pair<pii,pii>;

void solve()
{
    int n;
    cin >> n;
    vector<ppp> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].f.f >> a[i].f.s >> a[i].s.f >> a[i].s.s;
        if (a[i].f.f > a[i].s.f) swap(a[i].f, a[i].s);
    }

    int m;
    cin >> m;
    vpi points(m);

    for (int i = 0; i < m; i++) {
        cin >> points[i].f >> points[i].s;
    }

    vi ans;
    for (auto point : points) {
    
        while (true) {
            pii id = {-1, -1};
            double dist = -1;

            for(auto segment : a) {
                int mnx = min(segment.f.f, segment.s.f);
                int mxx = max(segment.f.f, segment.s.f);
                

                if (point.f >= mnx && point.f <= mxx) {
                    vi p = {segment.s.f - segment.f.f, segment.s.s - segment.f.s};

                    double py;
                    if (p[1] >= 0) 
                        py = 1LL*abs(point.f - segment.f.f) * abs(1.0 * p[1] / p[0]);
                    else 
                        py = 1LL*abs(segment.s.f - point.f) * abs(1.0 * p[1] / p[0]);

                    double y = py + min(segment.f.s, segment.s.s);

                    if (point.s > y) {
                        
                        if (dist < y) {
                            dist = y;
                            if (p[1] >= 0) {
                                id = segment.f;
                            }
                            else {
                                id = segment.s;
                            }
                        }
                    }
                }
            }

            if(id.f == -1) break;
            else point = id;
        }
        ans.pb(point.f);
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
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
