#include<bits/stdc++.h>
using namespace std;

const int N = 25;

deque<int> g[N];
int position[N];

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        g[i].push_back(i);
        position[i] = i;
    }
    string cmd, by;
    int a, b;
    while (cin >> cmd) {
        if (cmd == "quit") break;
        cin >> a >> by >> b;
        if (a == b || position[a] == position[b]) continue;
        if (cmd == "move") {
            int tmp = g[position[a]].back();
            while (tmp != a) {
                position[tmp] = tmp;
                g[tmp].push_back(tmp);
                g[position[a]].pop_back();
                tmp = g[position[a]].back();
            }
            if (by == "onto") {
                tmp = g[position[b]].back();
                while (tmp != b) {
                    g[tmp].push_back(tmp);
                    position[tmp] = tmp;
                    g[position[b]].pop_back();
                    tmp = g[position[b]].back();
                }
            }
            g[position[b]].push_back(a);
            g[position[a]].pop_back();
            position[a] = position[b];
        }
        else {
            if (by == "onto") {
                int tmp = g[position[b]].back();
                while (tmp != b) {
                    position[tmp] = tmp;
                    g[tmp].push_back(tmp);
                    g[position[b]].pop_back();
                    tmp = g[position[b]].back();
                }
            }
            int tmp = g[position[a]].back();
            stack<int> h;
            while (tmp != a) {
                h.push(tmp);
                position[tmp] = position[b];
                g[position[a]].pop_back();
                tmp = g[position[a]].back();
            }
            h.push(a);
            g[position[a]].pop_back();
            position[a] = position[b];
            while (!h.empty()) {
                g[position[b]].push_back(h.top());
                h.pop();
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d:", i);
        if (g[i].empty()) puts("");
        else {
            for (int j = 0; j < g[i].size(); j++) {
                cout << " " << g[i][j];
            }
            puts("");
        }
    }
}
