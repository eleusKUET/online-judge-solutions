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

struct Vertex
{
    vector<int> next;
    char val;
    int endmark;
    int id;
    string str;
    Vertex(){val = endmark = id = 0; next = vector<int>(128);}
};

struct Trie
{
    vector<Vertex> trie;
    
    Trie(){trie.push_back(Vertex());}
    void insert(string &s) 
    {
        int root = 0;
        int last = -1;
        for (int i = 0; i < s.size(); i++) {
            char it = s[i];
            if (!trie[root].next[it]) {
                Vertex new_node;
                new_node.id = trie.size();
                new_node.val = it;
                trie[root].next[it] = new_node.id;
                trie.push_back(new_node);
            }
            root = trie[root].next[it];

            if (i + 1 < s.size() && s[i + 1] == '\\') {
                trie[root].endmark++;
                trie[root].str = s.substr(last + 1, i - last);
                last = i + 1;
            }
        }
        trie[root].endmark++;
        trie[root].str = s.substr(last + 1, s.size());
    }
    Vertex search(string &s) 
    {
        int root = 0;
        for (auto it : s) {
            if (!trie[root].next[it]) {
                return Vertex();
            }
            root = trie[root].next[it];
        }
        return trie[root];
    }
    void dfs(Vertex u, int cnt = 0)
    {
        if (u.endmark) {
            cout << string(cnt, ' ') << u.str << "\n";
        }
        for (int i = 0; i < 128; i++) {
            if (u.next[i]) {
                if (trie[u.next[i]].val == '\\') dfs(trie[u.next[i]], cnt + 1);
            }
        }
        for (int i = 0; i < 128; i++) {
            if (u.next[i]) {
                if (trie[u.next[i]].val != '\\') dfs(trie[u.next[i]], cnt);
            }
        }
    }
};

const int mod = 1e9 + 7;

const int N = 1e5;


void solve()
{
    int n;
    while (cin >> n && n) {
        Trie dict;

        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            dict.insert(s);
        }
        dict.dfs(dict.trie.front());
        cout << "\n";
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
