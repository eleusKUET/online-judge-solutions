#include "bits/stdc++.h"
using namespace std;

signed main()
{
    int a, b, c;
    while (cin >> a >> b >> c){
        int mn = INT_MAX;
        mn = min(a + b + c, mn);
        mn = min(a + b - c, mn);
        mn = min(a + b * c, mn);
        mn = min(a - b + c, mn);
        mn = min(a - b - c, mn);
        mn = min(a - b * c, mn);
        mn = min(a * b + c, mn);
        mn = min(a * b - c, mn);
        mn = min(a * b * c, mn);
        cout << mn << "\n";
    }
}
