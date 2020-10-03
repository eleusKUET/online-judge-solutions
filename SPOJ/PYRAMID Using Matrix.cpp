#include<bits/stdc++.h>
using namespace std;
 
const int N = 5;
void cofactor(double mat[N][N], double tmp[N][N], int r, int c, int n)
{
    int x = 0;
    int y = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == r || j == c) continue;
            tmp[x][y] = mat[i][j];
            y = (y + 1)%(n - 1);
        }
        x = (x + 1)%(n - 1);
    }
}
 
double det(double mat[N][N], int n)
{
    if (n == 1) return mat[0][0];
    double tmp[N][N];
    int sign = 1;
    double d = 0.0;
    for (int i = 0; i < n; i++) {
        cofactor(mat, tmp, 0, i, n);
        d += sign * mat[0][i] * det(tmp, n - 1);
        sign = -sign;
    }
    return d;
}
 
signed main()
{
    int t;
    cin >> t;
    while (t--) {
        double u, v, w, U, V, W;
        cin >> w >> v >> u >> U >> V >> W;
        double mat[N][N];
        for (int i = 0; i < N; i++) {
            mat[i][N - 1] = mat[N - 1][i] = 1.0;
            mat[i][i] = 0.0;
        }
        mat[0][1] = u * u;
        mat[0][2] = v * v;
        mat[0][3] = w * w;
        mat[1][0] = u * u;
        mat[2][0] = v * v;
        mat[3][0] = w * w;
        mat[2][1] = W * W;
        mat[1][2] = W * W;
        mat[3][1] = V * V;
        mat[1][3] = V * V;
        mat[3][2] = U * U;
        mat[2][3] = U * U;
        double ret = det(mat, N);
        cout << setprecision(4) << fixed << sqrt(ret / 288.0) << "\n";
    }
}
