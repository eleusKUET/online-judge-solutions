#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

const int N = 1005;
char g[N][N];
int vis[N][N];
int mask[N][N];
int R, C;
int dx[] = {1, 0, -1, 1, -1, 1, 0, -1};
int dy[] = {1, 1, 1, 0, 0, -1, -1, -1};

bool isvalid(int r, int c)
{
    return (r >= 0 && r < R && c >= 0 && c < C && g[r][c] != 'X');
}

void bfs(int r, int c, int fx, int fy)
{
    vis[r][c]++;
    queue<pii> q;
    q.push({r, c});
    mask[r][c] = 255;
    while (!q.empty()) {
        r = q.front().first;
        c = q.front().second;
        q.pop();
        if (fx == r && fy == c) {
            printf("%d\n", vis[r][c] - 1);
            return;
        }
        for (int i = 0; i < 8; i++) {
            int u = r + dx[i];
            int v = c + dy[i];
            while (isvalid(u, v)) {
                if (mask[u][v] & (1<<i)) break;
                if (vis[u][v] == 0) vis[u][v] = vis[r][c] + 1, q.push({u, v});
                else vis[u][v] = min(vis[u][v], vis[r][c] + 1);
                mask[u][v] |= (1<<i);
                u += dx[i];
                v += dy[i];
            }
        }
    }
    puts("-1");
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t--) {
        cin >> R >> C;
        int sx, sy;
        int fx, fy;
        for (int i = 0; i < R; i++) {
            scanf("%s", g[i]);
            for (int j = 0; j < C; j++) {
                vis[i][j] = 0;
                mask[i][j] = 0;
                if (g[i][j] == 'S') {
                    sx = i, sy = j;
                }
                if (g[i][j] == 'F') {
                    fx = i;
                    fy = j;
                }
            }
        }
        bfs(sx, sy, fx, fy);
    }
}
