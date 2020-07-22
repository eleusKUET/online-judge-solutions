#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define F first
#define S second

int r, c;
const int N = 1000;
vector<string> g[N];

ii room(string q)
{
    string x, y;
    for (int i = 0; i < q.size(); i++) {
        if (isdigit(q[i])) y += q[i];
        else x += q[i];
    }
    reverse(x.begin(), x.end());
    int base = 1;
    int num = 0;
    for (int i = 0; i < x.size(); i++) {
        num += base * (x[i] - 'A' + 1);
        base *= 26;
    }
    return {atoi(y.c_str()) - 1, num - 1};
}

string solve(string x)
{
    vector<string> ele;
    string tmp;
    for (int i = 1; i < x.size(); i++) {
        if (x[i] == '+') ele.push_back(tmp), tmp = "";
        else tmp += x[i];
    }
    ele.push_back(tmp);
    int sum = 0;
    for (int i = 0; i < ele.size(); i++) {
        ii pos = room(ele[i]);
        if (g[pos.F][pos.S][0] == '=') {
            g[pos.F][pos.S] = solve(g[pos.F][pos.S]);
        }
        sum += atoi(g[pos.F][pos.S].c_str());
    }
    return to_string(sum);
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> c >> r;
        string tmp;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> tmp;
                g[i].push_back(tmp);
            }
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (g[i][j][0] == '=') {
                    g[i][j] = solve(g[i][j]);
                }
            }
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (j > 0) cout << " ";
                cout << g[i][j];
            }
            cout << "\n";
            g[i].clear();
        }
    }
}
