#include "bits/stdc++.h"
using namespace std;

int lower_bound(vector<int> &a, int key)
{
    int lo = 0;
    int hi = (int)a.size() - 1;
    int ans = a.size();
    while (lo <= hi) {
        int mid = (long long) lo + hi >> 1;
        if (a[mid] < key) {
            lo = mid + 1;
            ans = mid;
        }
        else {
            hi = mid - 1;
        }
    }
    return ans;
}

int upper_bound(vector<int> &a, int key)
{
    int lo = 0;
    int hi = (int)a.size() - 1;
    int ans = a.size();
    while (lo <= hi) {
        int mid = (long long) lo + hi >> 1;
        if (a[mid] > key) {
            hi = mid - 1;
            ans = mid;
        }
        else {
            lo = mid + 1;
        }
    }
    return ans;
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int q;
    cin >> q;
    while (q--) {
        int h; cin >> h;
        int ans = lower_bound(a, h);
        if (ans != a.size()) {
            cout << a[ans] << " ";
        }
        else {
            cout << "X ";
        }
        ans = upper_bound(a, h);
        if (a.size() != ans) {
            cout << a[ans] << "\n";
        }
        else {
            cout << "X\n";
        }
    }
}
