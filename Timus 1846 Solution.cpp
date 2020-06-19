//Timus 1846
//Author Eleus Ahammad
//CSE, KUET

#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;

    int seg = sqrt(q);
    deque<int> v[seg];
    int cache[seg];
    int gcd[seg];
    memset(gcd, 0, sizeof gcd);
    unordered_map<int,stack<int>> seg_pos;
    memset(cache, 0, sizeof cache);
    char ch; int num;

    while (q--) {
        cin >> ch >> num;
        if (ch == '+') {
            int pos = seg - 1;
            while (pos > 0 && cache[pos] >= seg) pos--;
            v[pos].push_back(num);
            cache[pos]++;
            gcd[pos] = __gcd(gcd[pos], num);
            seg_pos[num].push(pos);
        }
        else {
            int pos = seg_pos[num].top();
            seg_pos[num].pop();
            for (int i = 0; i < v[pos].size(); i++) {
                if (v[pos][i] == num) {
                    while (i + 1 < v[pos].size())
                        v[pos][i] = v[pos][i + 1], i++;
                    v[pos].pop_back();
                }
            }
            cache[pos]--;
            gcd[pos] = 0;
            for (auto x : v[pos]) {
                gcd[pos] = __gcd(gcd[pos], x);
            }
        }
        int ans = 0;
        for (int i = 0; i < seg; i++)
            ans = __gcd(ans, gcd[i]);
        cout << ans + (ans == 0) << "\n";
    }
    return 0;
}
