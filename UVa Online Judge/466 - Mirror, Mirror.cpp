// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <sstream>

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(...)
#endif

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T> using Tree = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define f first
#define s second
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define vpi vector<pair<int,int>>
#define ll long long
#define pll pair<long long,long long>
#define vpl vector<pair<long long,long long>>
#define vll vector<long long>
#define lb lower_bound
#define ub upper_bound
#define Checkbit(a,i) (((a)>>(i))&1)
#define Setbit(a,i) ((a)^=1LL<<(i))

int n;

void rotate(vector<string> &a)
{
    vector<string> tmp(n, string(n, ' '));
    for (int i = 0; i < n; i++) {
        for (int j = 0, k = n - 1; j < n; j++, k--) {
            tmp[i][j] = a[k][i];
        }
    }
    a = tmp;
}

bool compare(vector<string> &a, vector<string> &b)
{
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != b[i][j]) return false;
        }
    }
    return true;
}

void reflect(vector<string> &a)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0, k = n - 1; j < k; j++, k--) {
            swap(a[j][i], a[k][i]);
        }
    }
}

void print(vector<string> &a)
{
    for (int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }
}

void solve(int cs)
{
    vector<string> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    
    if (compare(a, b)) {
        cout << "Pattern " << cs << " was preserved.\n";
        return;
    }
    vector<string> tmp = a;
    
    rotate(a);
    if (compare(a, b)) {
        cout << "Pattern " << cs << " was rotated 90 degrees.\n";
        return;
    }

    
    rotate(a);
    if (compare(a, b)) {
        cout << "Pattern " << cs << " was rotated 180 degrees.\n";
        return;
    }
    
    rotate(a);
    if (compare(a, b)) {
        cout << "Pattern " << cs << " was rotated 270 degrees.\n";
        return;
    }
    
    rotate(a);
    reflect(a);
    if (compare(a, b)) {
        cout << "Pattern " << cs << " was reflected vertically.\n";
        return;
    }
    
    rotate(a);
    if (compare(a, b)) {
        cout << "Pattern " << cs << " was reflected vertically and rotated 90 degrees.\n";
        return;
    }
    
    rotate(a);
    if (compare(a, b)) {
        cout << "Pattern " << cs << " was reflected vertically and rotated 180 degrees.\n";
        return;
    }

    rotate(a);
    if (compare(a, b)) {
        cout << "Pattern " << cs << " was reflected vertically and rotated 270 degrees.\n";
        return;
    }
    
    cout << "Pattern " << cs << " was improperly transformed.\n";
}

signed main()
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    int cs = 1;
    while (cin >> n) {
        //cout << "Case " << cs++ << ":" << " ";
        solve(cs++);
    }
}
