//UVa 10077
#include<bits/stdc++.h>
using namespace std;
using ii = pair<int,int>;

int main()
{
    ios::sync_with_stdio(0);
    int n, m;
    while (cin >> n >> m) {
        if (n == m && n == 1) break;
        string path;
        int lx = 0, ly = 1;
        int rx = 1, ry = 0;
        queue<ii> q;
        q.push({1, 1});
        while (!q.empty()) {
            int midx = q.front().first;
            int midy = q.front().second;
            q.pop();
            if (midx == n && midy == m) break;
            if (midx * m < midy * n) {
                path += 'R';
                q.push({midx + rx, midy + ry});
                lx = midx;
                ly = midy;
            }
            else {
                path += 'L';
                q.push({midx + lx, midy + ly});
                rx = midx;
                ry = midy;
            }
        }
        cout << path << "\n";
    }
}
