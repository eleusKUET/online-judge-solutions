#include "bits/stdc++.h"
using namespace std;

signed main()
{
    //freopen("input.txt", "r", stdin);
    int l, r, h;
    vector<array<int,3>> a;
    vector<int> sky(1e4 + 5);
    int mxr = 0;
    while(cin >> l >> h >> r) {
        a.push_back({l, r, h});
        for (int i = l; i < r; i++) {
            sky[i] = max(sky[i], h);
        }
        mxr = max(mxr, r);
    }
    vector<int> fin;
    for (int i = a[0][0], j; i <= mxr; i = j) {
        j = i;
        while (j <= mxr && sky[j] == sky[i]) {
            //debug(sky[j], j);
            j++;
        }
        fin.push_back(i);
        fin.push_back(sky[i]);
    }
    for (int i = 0; i < fin.size(); i++) {
        if (i > 0) cout << " ";
        cout << fin[i];
    }
    cout << "\n";
}
