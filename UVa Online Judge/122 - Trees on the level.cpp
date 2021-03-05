#include "bits/stdc++.h"
using namespace std;

void process(string a, string &b, int &v)
{
    int i; string h;
    for (i = 1; i < a.size() && a[i] != ','; i++)
        h += a[i];
    for (i = i + 1; i < a.size() && a[i] != ')'; i++)
        b += a[i];
    v = atoi(h.c_str());
}

bool solve()
{
    vector<string> a;
    string h;
    while (cin >> h) {
        if (h == "()") break;
        a.push_back(h);
    }
    if (a.empty()) return false;
    map<string,int> node;
    map<string,int> cnt;
    for (int i = 0; i < a.size(); i++) {
        int v;
        h = "";
        process(a[i], h, v);
        cnt[h]++;
        node[h] = v;
        //debug(h, v, a[i], cnt[h], node[h]);
        if (cnt[h] > 1) {
            puts("not complete");
            return true;
        }
    }
    queue<string> q;
    q.push("");
    vector<int> v;
    while (!q.empty()) {
        string u = q.front();
        q.pop();
        if (!node[u]) {
            puts("not complete");
            return true;
        }
        v.push_back(node[u]);
        //debug(v.back());
        if (node[u + "L"]) {
            q.push(u + "L");
        }
        if (node[u + "R"]) {
            q.push(u + "R");
        }
    }
    if (v.size() != a.size()) {
        puts("not complete");
        return true;
    }
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i + 1 < v.size()) cout << " ";
        else cout << "\n";
    }
    return true;
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    while (solve());
}
