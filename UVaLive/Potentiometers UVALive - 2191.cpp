#include "bits/stdc++.h"
using namespace std;

const int N = 2e5 + 5;
int tree[N * 4];

void update(int l, int r, int val, int pos, int i)
{
    if (pos > r || pos < l) return;
    if (l == r) {
        tree[i] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) update(l, mid, val, pos, i * 2);
    else update(mid + 1, r, val, pos, i * 2 + 1);
    tree[i] = tree[i * 2] + tree[i * 2 + 1];
}

int query(int l, int r, int f, int s, int i)
{
    if (l > s || r < f) return 0;
    if (f <= l && r <= s) return tree[i];
    int mid = (l + r) / 2;
    return query(l, mid, f, s, i * 2) + query(mid + 1, r, f, s, i * 2 + 1);
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    int n, cs = 0;
    while (cin >> n) {
        if (n == 0) break;
        for (int i = 1; i <= n; i++) {
            int h; cin >> h;
            update(1, n, h, i, 1);
        }
        string cmd;
        if (cs++) cout << "\n";
        cout << "Case " << cs++ << ":\n";
        while (cin >> cmd) {
            if (cmd == "END") break;
            int pos, val;
            cin >> pos >> val;
            if (cmd == "M") {
                cout << query(1, n, pos, val, 1) << "\n";
            }
            else {
                update(1, n, val, pos, 1);
            }
        }
    }
}
