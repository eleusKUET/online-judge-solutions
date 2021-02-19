#include "bits/stdc++.h"
using namespace std;

bool leap(int a)
{
    return (a%400 == 0 || a%100 && a%4 == 0);
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    array<int,13> mon = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int n;
    while (cin >> n) {
        if (n == 0) break;
        vector<array<int,4>> a(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> a[i][j];
            }
        }
        int cnt = 0;
        int def = 0;
        for (int i = 1; i < n; i++) {
            if (a[i][2] == a[i - 1][2]) {
                mon[2] += leap(a[i][2]);
                if (a[i][1] == a[i - 1][1]) {
                    if (a[i][0] == a[i - 1][0] + 1) {
                        def += a[i][3] - a[i - 1][3];
                        cnt++;
                    }
                }
                else if (a[i][1] == a[i - 1][1] + 1) {
                    if (a[i][0] == 1 && mon[a[i - 1][1]] == a[i - 1][0]) {
                        cnt++;
                        def += a[i][3] - a[i - 1][3];
                    }
                }
                mon[2] -= leap(a[i][2]);
            }
            else if (a[i][2] == a[i - 1][2] + 1) {
                if (a[i][1] == 1 && a[i][0] == 1 && a[i - 1][1] == 12 && a[i - 1][0] == 31) {
                    cnt++;
                    def += a[i][3] - a[i - 1][3];
                }
            }
        }
        cout << cnt << " " << def << "\n";
    }
}
