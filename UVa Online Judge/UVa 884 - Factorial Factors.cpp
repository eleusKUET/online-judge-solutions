#include "bits/stdc++.h"
using namespace std;

vector<int> prime;
const int N = 1e6 + 5;
bitset<N> mark;
int sp[N];

void sieve()
{
    int limit = sqrt(N);
    mark[1] = 1;
    sp[1] = 1;
    sp[2] = 2;
    for (int i = 4; i < N; i += 2) mark[i] = 1, sp[i] = 2;
    prime.push_back(2);

    for (int i = 3; i < N; i += 2) {
        if (!mark[i]) {
            sp[i] = i;
            prime.push_back(i);
            if (i <= limit) {
                for (int j = i * i; j < N; j += 2 * i) {
                    mark[j] = 1;
                    sp[j] = i;
                }
            }
        }
    }
}

int cnt[N];

int factor(int n)
{
    int cnt = 0;
    while (n > 1) {
        n /= sp[n];
        cnt++;
    }
    return cnt;
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    sieve();
    for (int i = 2; i < N; i++) {
        cnt[i] += cnt[i - 1] + factor(i);
    }
    int n;
    while (cin >> n) {
        cout << cnt[n] << "\n";
    }
}
