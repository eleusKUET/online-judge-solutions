//Using multisource BFS
#include<bits/stdc++.h>
using namespace std;
using ii = pair<int,int>;

const int N = 200;
char g[N][N];
bool vis[N][N];
int dist[N][N];

int R, C;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool isvalid(int r, int c)
{
    return (r >= 0 && r < R && c >= 0 && c < C && g[r][c] == '0');
}

int main()
{
    ios::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        cin >> R >> C;
        queue<ii> q;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> g[i][j];
                dist[i][j] = INT_MAX;
                if (g[i][j] == '1') {
                    q.push({i, j});
                    dist[i][j] = 0;
                    vis[i][j] = true;
                }
            }
        }

        while (!q.empty()) {
            int u = q.front().first;
            int v = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int r = u + dx[i];
                int c = v + dy[i];
                if (isvalid(r, c) && !vis[r][c]) {
                    vis[r][c] = true;
                    q.push({r, c});
                    dist[r][c] = min(dist[r][c], dist[u][v] + 1);
                }
            }
        }
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (j > 0) cout << " ";
                cout << dist[i][j];
                vis[i][j] = false;
            }
            cout << "\n";
        }
    }
}
