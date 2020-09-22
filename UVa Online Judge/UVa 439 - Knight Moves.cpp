//UVa 439
//Author: Eleus Ahammad
//CSE, KUET
#include<bits/stdc++.h>
using namespace std;
using ii = pair<int,int>;

const int N = 8;
map<ii, int> vis;
map<ii,ii> path;

int dx[] = {-2, -2, 2, 2, -1, -1, 1, 1};
int dy[] = {-1, 1, -1, 1, -2, 2, -2, 2};

bool isvalid(ii a)
{
    return (a.first >= 1 && a.first <= N && a.second >= 1 && a.second <= N);
}

void bfs(ii u, ii v)
{
    vis[u]++;
    queue<ii> q;
    q.push(u);
    path[u] = u;
    while (!q.empty()) {
        u = q.front();
        q.pop();
        if (u == v) return;
        for (int i = 0; i < 8; i++) {
            ii v = {u.first + dx[i], u.second + dy[i]};
            if (isvalid(v) && !vis[v]) {
                vis[v]++;
                q.push(v);
                path[v] = u;
            }
        }
    }
}

int main()
{
    string a, b;
    ios::sync_with_stdio(0);
    while (cin >> a >> b) {
        ii init = {a[0] - 'a' + 1, a[1] - '0'};
        ii stop = {b[0] - 'a' + 1, b[1] - '0'};
        bfs(init, stop);
        int cnt = 0;
        while (path[stop] != stop) {
            stop = path[stop];
            cnt++;
        }
        cout << "To get from " << a << " to " << b << " takes " << cnt << " knight moves.\n";
        path.clear();
        vis.clear();
    }
}
