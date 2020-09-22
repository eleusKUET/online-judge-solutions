#include<bits/stdc++.h>
using namespace std;

map<int, int> cache;

bool comp(int a, int b)
{
    if (cache[a] < cache[b]) return true;
    return false;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);

    int cs = 1;
    int c, s;
    while (cin >> c >> s) {
        vector<int> v[c], x(s);
        int tmp = 0;

        for (auto &val:x) {
            cin >> val;
            cache[val] = tmp++;
        }
        sort(x.rbegin(), x.rend());
        double avg = 0.0;
        for (auto val:x) avg += val;
        avg /= c;

        for (int i = 0; i < c && i < s; i++) {
            v[i].push_back(x[i]);
        }
        for (int i = c - 1, j = c; i >= 0 && j < s; i--, j++) {
            v[i].push_back(x[j]);
        }
        double imbalance = 0.0;
        for (int i = 0; i < c; i++) {
            int sum = 0;
            for (auto ele : v[i]) sum += ele;
            imbalance += abs(sum - avg);
        }

        printf("Set #%d\n", cs++);
        for (int i = 0; i < c; i++) {
            printf(" %d:", i);
            sort(v[i].begin(), v[i].end(), comp);
            for (auto ele : v[i]) cout << " " << ele;
            puts("");
        }
        printf("IMBALANCE = %0.5f\n\n", imbalance);
    }
}
