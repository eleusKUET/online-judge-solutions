#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; //check the limits, dummy

ll __lcm(ll a, ll b)
{
    return a * b / __gcd(a, b);
}

void solve() {
    int n, m;
    while (cin >> n >> m) {
        vi a(m);
        for (int i = 0; i < m; i++) {
            cin >> a[i];
        }
        int cnt = 0;
        for (int i = 1; i < (1<<m); i++) {
            ll lcm = 1;
            for (int j = 0; j < m; j++) {
                if (i & (1<<j)) {
                    lcm = __lcm(lcm, a[j]);
                }
            }
            if (__builtin_popcount(i)%2) cnt += n / lcm;
            else cnt -= n / lcm;
        }
        cout << n - cnt << nl;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);

    int T = 1;
    //cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343

