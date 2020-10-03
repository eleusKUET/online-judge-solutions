#include<bits/stdc++.h>
using namespace std;
#define XOX
vector<string> vec_splitter(string s) {
	s += ',';
	vector<string> res;
	while(!s.empty()) {
		res.push_back(s.substr(0, s.find(',')));
		s = s.substr(s.find(',') + 1);
	}
	return res;
}
void debug_out(
vector<string> __attribute__ ((unused)) args,
__attribute__ ((unused)) int idx,
__attribute__ ((unused)) int LINE_NUM) { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
	if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
	stringstream ss; ss << H;
	cerr << args[idx] << " = " << ss.str();
	debug_out(args, idx + 1, LINE_NUM, T...);
}
#ifdef XOX
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define debug(...) 42
#endif
//Start

signed main()
{
    //freopen("input.txt", "r", stdin);
    int s, w, c, k, m;
    while (cin >> s >> w >> c >> k >> m) {
        priority_queue<int,vector<int>,greater<int>> p;
        for (int i = 1; i <= k; i++) {
            p.push(i * m + s);
        }
        int rs = 0;
        int done = -1;
        while (rs < 10000) {
            int tm = p.top();
            p.pop();
            if (tm < done) tm = done;
            done = tm + w;
            rs += c;
            //debug(tm, done, rs);
            p.push(done + s + s);
        }
        cout << done + s << "\n";
    }
}
