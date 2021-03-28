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

vi prime;
bitset<MX + 5> mark;

void sieve()
{
    int limit = sqrt(MX);
    for (int i = 4; i <= MX; i += 2) mark[i] = 1;
    prime.pb(2);
    mark[1] = 1;
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

void even(int n)
{
    for (int i = 0; i < sz(prime); i++) {
        if (n - prime[i] > 0 && !mark[n - prime[i]]) {
            cout << prime[i] << " " << n - prime[i] << nl;
            return;
        }
    }
}

void solve() {
    int n;
    while (cin >> n) {
        if (n < 8) {
            cout << "Impossible." << nl;
            continue;
        }
        if (n & 1) {
            cout << 2 << " " << 3 << " ";
            even(n - 5);
        }
        else {
            cout << 2 << " " << 2 << " ";
            even(n - 4);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    sieve();

    int T = 1;
    //cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343
