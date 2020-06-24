//UVA 352
//Author: Eleus Ahammad
//CSE,KUET
#include<bits/stdc++.h>
using namespace std;

int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int N = 25;

int g[N][N];
int vis[N][N];
int n; // take input dimension

bool isvalid(int r, int c)
{
    return (r >= 0 && r < n && c >= 0 && c < n && g[r][c]);
}

void dfs(int r, int c, int id)
{
    vis[r][c] = id;
    for (int i = 0; i < 8; i++) {
        if (isvalid(r + dx[i], c + dy[i]) && !vis[r + dx[i]][c + dy[i]])
            dfs(r + dx[i], c + dy[i], id);
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int cs = 1;
    while (cin >> n) {
        string x;
        for (int i = 0; i < n; i++) {
            cin >> x;
            for (int j = 0; j < n; j++) {
                g[i][j] = x[j] - '0';
            }
        }
        int id = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][j] == 0 || vis[i][j]) continue;
                dfs(i, j, id);
                id++;
            }
        }
        cout << "Image number " << cs++ << " contains " << id - 1 << " war eagles.\n";
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                g[i][j] = vis[i][j] = 0;
    }
}
