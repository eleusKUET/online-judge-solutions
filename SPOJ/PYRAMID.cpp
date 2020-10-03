#include<bits/stdc++.h>
using namespace std;
 
signed main()
{
    int t;
    cin >> t;
    while (t--) {
        double u, v, w, U, V, W;
        cin >> w >> v >> u >> U >> V >> W;
        double X, x, Y, y, Z, z;
        X = (w - U + v) * (U + v + w);
        x = (U - v + w) * (v - w + U);
        Y = (u - V + w) * (u + V + w);
        y = (V - w + u) * (w - u + V);
        Z = (v - W + u) * (W + u + v);
        z = (W - u + v) * (u - v + W);
        double a = sqrt(x * Y * Z);
        double b = sqrt(X * y * Z);
        double c = sqrt(z * X * Y);
        double d = sqrt(x * y * z);
        double ret = sqrt((- a + b + c + d) * (a - b + c + d) * (a + b - c + d) * (a + b + c - d));
        cout << setprecision(4) << fixed << ret / (192.0 * u * v * w) << "\n";
    }
}
