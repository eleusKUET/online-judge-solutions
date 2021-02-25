#include "bits/stdc++.h"
using namespace std;
using vi = vector<int>;

vi add(vi &a, vi &b)
{
    if (a.size() < b.size()) swap(a, b);
    int carry = 0;
    vi ans;
    for (int i = 0; i < b.size(); i++) {
        int sum = a[i] + b[i] + carry;
        ans.push_back(sum%10);
        carry = sum / 10;
    }
    for (int i = b.size(); i < a.size(); i++) {
        int sum = a[i] + carry;
        ans.push_back(sum%10);
        carry = sum / 10;
    }
    while (carry > 0) {
        ans.push_back(carry%10);
        carry /= 10;
    }
    return ans;
}

vi reverse(vi a)
{
    vi b;
    int stop = 0;
    while (stop < a.size() && a[stop] == 0) stop++;
    for (int i = (int) a.size() - 1; i >= stop; i--) {
        b.push_back(a[i]);
    }
    return b;
}

vi readInt()
{
    string a; cin >> a;
    vi num(a.size());
    for (int i = 0; i < a.size(); i++) {
        num[i] = a[i] - '0';
    }
    reverse(num);
    return num;
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    int t; cin >> t;
    while (t--) {
        vi a, b;
        a = readInt();
        b = readInt();
        a = add(a, b);
        a = reverse(a);
        while (!a.empty()) {
            cout << a.back();
            a.pop_back();
        }
        cout << "\n";
    }
}
