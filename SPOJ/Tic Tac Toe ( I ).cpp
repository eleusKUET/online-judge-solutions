#include<bits/stdc++.h>
using namespace std;
 
bool is_win(string a)
{
    bool row = (a[0] != '.' && a[0] == a[1] && a[1] == a[2]) ||
               (a[3] != '.' && a[3] == a[4] && a[4] == a[5]) ||
               (a[6] != '.' && a[6] == a[7] && a[7] == a[8]);
    bool col = (a[0] != '.' && a[0] == a[3] && a[3] == a[6]) ||
               (a[1] != '.' && a[1] == a[4] && a[4] == a[7]) ||
               (a[2] != '.' && a[5] == a[2] && a[5] == a[8]);
    bool dia = (a[0] != '.' && a[0] == a[4] && a[4] == a[8]) ||
               (a[2] != '.' && a[2] == a[4] && a[2] == a[6]);
    return row || col || dia;
}
 
int main()
{
    int t;
    cin >> t;
    while (t--) {
        string board, row;
        for (int i = 0; i < 3; i++) {
            cin >> row;
            board += row;
        }
        queue<pair<string, bool>> q;
        q.push({".........", 1});
        string ans = "no";
        while (!q.empty()) {
            string v = q.front().first;
            bool play = q.front().second;
            q.pop();
            if (v == board) {
                ans = "yes";
                break;
            }
            if (is_win(v)) continue;
            for (int i = 0; i < 9; i++) {
                if (v[i] == '.') {
                    v[i] = (play ? 'X' : 'O');
                    if (v[i] == board[i])
                        q.push({v, 1 ^ play});
                    v[i] = '.';
                }
            }
        }
        cout << ans << "\n";
    }
}
