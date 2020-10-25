#include "bits/stdc++.h"
using namespace std;

signed main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    int cs = 1;
    while (cin >> n) {
        if (n == 0) break;
        map<string,int> node;
        vector<string> idx;
        int top = 0;

        int g[200][200];
        memset(g, 0, sizeof g);

        for (int i = 0; i < n; i++) {
            int h;
            cin >> h;
            int f = top;
            for (int j = 0; j < h; j++) {
                string tmp;
                cin >> tmp;
                node[tmp] = top++;
                idx.push_back(tmp);
            }
            for (int i = f; i < top - 1; i++) {
                g[i][i + 1] = 1;
            }
        }
        int h;
        cin >> h;
        while (h--) {
            string a, b;
            cin >> a >> b;
            g[node[a]][node[b]] = 1;
        }
        for (int k = 0; k < top; k++) {
            for (int i = 0; i < top; i++) {
                for (int j = 0; j < top; j++) {
                    if (g[i][k] && g[k][j]) {
                        g[i][j] = 1;
                    }
                }
            }
        }
        int cnt = 0;
        string ans = "";
        for (int i = 0; i < top; i++) {
            for (int j = i + 1; j < top; j++) {
                if (g[i][j] == 0 && g[j][i] == 0) {
                    cnt++;
                    if (cnt <= 2) ans = ans + "(" + idx[i] + "," + idx[j] + ") ";
                }
            }
        }
        cout << "Case " << cs++ << ", ";
        if (cnt == 0) {
            cout << "no concurrent events.\n";
        }
        else {
            cout << cnt << " concurrent events:\n";
            cout << ans << "\n";
        }
    }
}
