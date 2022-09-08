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

#ifdef __LOCAL__
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

const int mod = 1e9 + 7;

const int N = 128;

int n;
char a[N];

int dp[N][N];
int K[N][N];

int g(int x, int y)
{
    if (a[x] == '(' && a[y] == ')') return 0;
    if (a[x] == '[' && a[y] == ']') return 0;
    return 1;
}

string help(char a)
{
    if (a == '(' || a == ')') return "()";
    return "[]";
}

int f(int x, int y)
{
    if (x > y) return 0;
    if (x == y) {
        return dp[x][y] = 1;
    }
    
    int &ret = dp[x][y];
    if (ret != -1) return ret;
    ret = 2e9;
    
    if (g(x, y) == 0) {
        ret = f(x + 1, y - 1);
    }
    
    for (int i = x; i < y; i++) {
        int tmp = f(x, i) + f(i + 1, y);
        if (tmp < ret) {
            ret = tmp;
            K[x][y] = i;
        }
    }
    
    return ret;
}

void print(int x, int y)
{
    if (x > y) return;
    if (x == y) {
        cout << help(a[x]);
        return;
    }
    int k = K[x][y];
    if (k == -1) {
        cout << a[x];
        print(x + 1, y - 1);
        cout << a[y];
    }
    else {
        print(x, k);
        print(k + 1, y);
    }
}

void solve()
{
    gets(a + 1);
    gets(a + 1);
    n = strlen(a + 1); 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = -1;
            K[i][j] = -1;
        }
    }
    f(1, n);
    print(1, n);
    printf("\n");
}

signed main()
{
    // freopen("input.txt", "r", stdin);
    
    int t = 1;
    scanf("%d", &t);
    getchar();
    while (t--) {
        //cout << "Case " << cs++ << ":" << " ";
        solve();
        if (t) puts("");
    }
}
