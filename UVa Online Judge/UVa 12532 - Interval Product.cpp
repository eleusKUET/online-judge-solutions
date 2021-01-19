#include "bits/stdc++.h"9
using namespace std;

const int N = 1e5 + 5;
int prod[4 * N];
int a[N];

void update(int id, int l, int r, int pos)
{
    if (pos > r || pos < l) return;
    if (l == pos && pos == r) {
        prod[id] = a[pos];
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) update(id * 2, l, mid, pos);
    else update(id * 2 + 1, mid + 1, r, pos);
    prod[id] = prod[id * 2] * prod[id * 2 + 1];
}

int query(int l, int r, int start, int nd, int id)
{
    if (l > nd || r < start) return 1;
    if (start <= l && r <= nd) return prod[id];
    int mid = (l + r) / 2;
    int x = query(l, mid, start, nd, id * 2);
    int y = query(mid + 1, r, start, nd, id * 2 + 1);
    return x * y;
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    while (cin >> n >> k) {
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            a[i] = (a[i] > 0) ? 1 : (a[i] < 0) ? -1 : 0;
            update(1, 1, n, i);
        }
        char type;
        int l, r;
        while (k--) {
            cin >> type >> l >> r;
            if (type == 'C') {
                a[l] = (r > 0) ? 1 : (r < 0) ? -1 : 0;
                update(1, 1, n, l);
            }
            else {
                int c = query(1, n, l, r, 1);
                if (c > 0) cout << "+";
                else if (c < 0) cout << "-";
                else cout << "0";
            }
        }
        cout << "\n";
    }
}
