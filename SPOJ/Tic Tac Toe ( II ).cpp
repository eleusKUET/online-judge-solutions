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
 
bool is_full(string a)
{
    int cnt = 0;
    for (int i = 0; i < a.size(); i++)
        cnt += a[i] == '.';
    return cnt == 0;
}
 
int main()
{
    ios::sync_with_stdio(0);
    string board;
    while (cin >> board) {
        if (board == "end") break;
        queue<pair<string, bool>> q;
        q.push({".........", 1});
        string ans = "invalid";
        while (!q.empty()) {
            string v = q.front().first;
            bool play = q.front().second;
            q.pop();
            if (v == board) {
                ans = "valid";
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
        if (ans == "valid") {
            if (!is_full(board) && !is_win(board)) ans = "invalid";
        }
        cout << ans << "\n";
    }
}
