#include "bits/stdc++.h"
using namespace std;

const int N = 1e6 + 5;

bitset<N> mark;
int small[N];

void sieve()
{
    int limit = sqrt(N);
    mark[1] = 1; small[2] = 2;
    for (int i = 4; i < N; i += 2) mark[i] = 1, small[i] = 2;
    for (int i = 3; i < N; i += 2) {
        if (!mark[i]) {
            small[i] = i;
            if (i <= limit) {
                for (int j = i * i; j < N; j += 2 * i) {
                    mark[j] = 1; small[j] = i;
                }
            }
        }
    }
}

int factor(int n)
{
    int cnt = 1;
    while (small[n]) {
        int p = 0, h = small[n];
        while (n%h == 0) {
            n /= h;
            p++;
        }
        cnt *= p + 1;
    }
    return cnt;
}

int perfect[N];

void pre()
{
    for (int i = 2; i * i < N; i += 2) {
        for (int j = 2 * i * i; j < N; j += i * i) {
            perfect[j]++;
        }
    }
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    sieve();
    pre();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (perfect[n]) {
            int q = factor(n) - 1;
            int p = perfect[n];
            int gcd = __gcd(p, q);
            cout << p / gcd << "/" << q / gcd << "\n";
        }
        else {
            cout << "0\n";
        }
    }

}
