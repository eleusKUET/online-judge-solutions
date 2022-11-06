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
#include <numeric>

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(...)
#endif

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T> using oset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template <class K,class V> using omap = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

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

const int mod = 1e9 + 7;

const int N = 1e5;

int weight(char a)
{
    if (a == '+' || a == '-') return 1;
    if (a == '/' || a == '*') return 2;
    return 0;
}

string postfix(const string &str)
{
    stack<char> s;
    string res;
    for (auto c : str) {
        if (isdigit(c)) res += c;
        else if (c == '(') s.push(c);
        else if (c == ')') {
            while (s.top() != '(') {
                res += s.top();
                s.pop();
            }
            s.pop();
        }
        else {
            while (s.size() && weight(s.top()) >= weight(c)) {
                res += s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    while (s.size()) {
        res += s.top();
        s.pop();
    }
    return res;
}

void solve()
{
    string exp;
    char tt[10];
    while (gets(tt) && strlen(tt)) {
        if (tt[0] == ' ') break;
        // debug(ch);
        exp += string(tt);
    }
    // debug(exp);
    cout << postfix(exp) << "\n";
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    char tt[10];
    gets(tt);
    t = atoi(tt);
    // debug(t);
    gets(tt);
    // debug(string(tt));
    int cs = 1;
    while (t--) {
        //cout << "Case " << cs++ << ":" << " ";
        solve();
        if (t) cout << "\n";
    }
}
