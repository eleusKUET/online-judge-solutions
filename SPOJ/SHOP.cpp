#include<bits/stdc++.h>
using namespace std;
 
struct edge {
    int Row, Col, Cost; edge(int r, int c, int w) {
        Row = r, Col = c, Cost = w;
    }
};
 
int R, C;
 
char grid[30][30];
int cost[30][30];
 
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
 
bool isvalid(int r, int c)
{
    return (r >= 0 && r < R && c >= 0 && c < C && (isdigit(grid[r][c]) || grid[r][c] == 'S' || grid[r][c] == 'D'));
}
 
void dijkstra(int r, int c)
{
    auto cmp = [] (edge a, edge b) {
        return a.Cost > b.Cost;
    };
    priority_queue<edge, vector<edge>, decltype(cmp)> q(cmp);
    cost[r][c] = 0;
    q.push(edge(r, c, 0));
    while (!q.empty()) {
        edge u = q.top();
        q.pop();
        for (int i = 0; i < 4; i++) {
            r = u.Row + dx[i];
            c = u.Col + dy[i];
            if (isvalid(r, c)) {
                int dist = cost[u.Row][u.Col];
                if (isdigit(grid[r][c])) dist += grid[r][c] - '0';
                if (dist < cost[r][c]) {
                    cost[r][c] = dist;
                    q.push(edge(r, c, cost[r][c]));
                }
            }
        }
    }
}
 
signed main()
{
    //freopen("input.txt", "r", stdin);
    while (cin >> C >> R) {
        if (!R && !C) break;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cost[i][j] = INT_MAX;
                cin >> grid[i][j];
            }
        }
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (grid[i][j] == 'S') {
                    dijkstra(i, j);
                    i = R;
                    break;
                }
            }
        }
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (grid[i][j] == 'D') {
                    cout << cost[i][j] << "\n";
                    i = R;
                    break;
                }
            }
        }
    }
}
