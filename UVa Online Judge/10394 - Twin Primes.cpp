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
const int MX = 2e7 + 1; //check the limits, dummy

vector<int> prime;
bitset<MX + 5> mark;

void sieve()
{
    int limit = sqrt(MX);
    for (int i = 4; i <= MX; i += 2) mark[i] = 1;
    prime.pb(2);
    for (int i = 3; i <= MX; i += 2) {
        if (!mark[i]) {
            prime.pb(i);
            //cout << prime.back() << nl;
            if (i <= limit) {
                for (int j = i * i; j <= MX; j += 2 * i) {
                    mark[j] = 1;
                }
            }
        }
    }
}

vector<pi> ans;

void pre()
{
    for (int i = 0; i + 1 < sz(prime); i++) {
        if (prime[i] + 2 == prime[i + 1]) {
            ans.pb(mp(prime[i], prime[i + 1]));
        }
    }
}

void solve() {
    int a;
    while (cin >> a) {
        printf("(%d, %d)\n", ans[a - 1].f, ans[a - 1].s);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    sieve();
    pre();
    int T = 1;
    //cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343
