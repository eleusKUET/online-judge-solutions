#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    int d[n], h[n];
    for (int i = 0; i < n; i++) {
        cin >> d[i] >> h[i];
    }
    stack<int> s;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s.empty()) {
            cnt++;
            s.push(h[i]);
        }
        else {
            if (s.top() < h[i]) {
                cnt++;
                s.push(h[i]);
            }
            else {
                while (s.top() > h[i]) {
                    s.pop();
                    if (s.empty()) break;
                }
                if (!s.empty() && s.top() == h[i]) continue;
                else {
                    s.push(h[i]);
                    cnt++;
                }
            }
        }
    }
    cout << cnt << "\n";
}
