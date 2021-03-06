#include "bits/stdc++.h"
using namespace std;

struct team {
    int a, b, c;
};

bool _comp(team p, team q)
{
    if (p.b == q.b) return p.c < q.c;
    return p.b > q.b;
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    int n; cin >> n;
    team a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i].a >> a[i].b;
        a[i].c = i;
    }
    sort(a, a + n, _comp);
    for (int i = 0; i < n; i++) {
        cout << a[i].a << " " << a[i].b << "\n";
    }
}
