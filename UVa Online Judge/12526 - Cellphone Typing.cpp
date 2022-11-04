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

struct Vertex {
    vector<int> next;
    int id;
    char val;
    int endmark;
    Vertex(){id = val = endmark = 0; next = vector<int>(26);}
};

struct Trie {
    vector<Vertex> trie;
    Trie(){trie.push_back(Vertex());}
    void insert(const string &s) {
        int root = 0;
        for (auto it : s) {
            int c = it - 'a';
            if (!trie[root].next[c]) {
                Vertex new_node;
                new_node.id = trie.size();
                new_node.val = it;
                trie[root].next[c] = new_node.id;
                trie.push_back(new_node);
            }
            root = trie[root].next[c];
        }
        trie[root].endmark++;
    }
    int search(const string &s) {
        vector<Vertex> res;
        int root = 0;
        for (auto it : s) {
            int c = it - 'a';
            root = trie[root].next[c];
            res.push_back(trie[root]);
        }
        int cnt = 1;
        for (int i = 1; i < res.size(); i++) {
            int mul = 0;
            for (int j = 0; j < 26; j++) mul += !!res[i - 1].next[j];
            if (res[i - 1].endmark || mul > 1) {
                cnt++;
            } 
        }
        return cnt;
    }
};

const int mod = 1e9 + 7;

const int N = 1e5;


void solve()
{
    int n;
    while (cin >> n && n) {
        Trie dict;
        vector<string> a(n);

        for (int i = 0; i < n; i++){
            cin >> a[i];
            dict.insert(a[i]);
        }
        cout << setprecision(2) << fixed;
        long long sum = 0;
        for (auto it : a) {
            sum += dict.search(it);
        }

        cout << 1.0 * sum / n << "\n";
    }
}   

signed main()
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    int cs = 1;
    while (t--) {
        //cout << "Case " << cs++ << ":" << " ";
        solve();
    }
}
