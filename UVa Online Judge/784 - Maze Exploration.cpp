#include "bits/stdc++.h"
using namespace std;

void dfs(vector<string> &a, int r, int c)
{
    if (r < 0 || c < 0 || r >= a.size() || c >= a[r].size()) return;
    if (a[r][c] != ' ' && a[r][c] != '*') return;
    a[r][c] = '#';
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (abs(i) == abs(j)) continue;
                dfs(a, r + i, c + j);
        }
    }
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    string h;
    getline(cin, h);
    t = atoi(h.c_str());
    while (t--) {
        vector<string> a;
        while (getline(cin, h)) {
            int cnt = 0;
            for (auto it : h) {
                if (it == '-') cnt++;
            }
            a.push_back(h);
            if (cnt == h.size()) break;
        }
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < a[i].size(); j++) {
                if (a[i][j] == '*') {
                    dfs(a, i, j);
                }
            }
        }
        for (auto u : a) {
            cout << u << "\n";
        }
    }
}
