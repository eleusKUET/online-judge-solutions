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
#define int long long

signed main()
{
    //freopen("input.txt", "r", stdin);
    int a, b;
    while (cin >> a >> b) {
        if (a == 0 && b == 0) break;

        int cnt = 0;
        if (a < b) swap(a, b);
        while (a%b && a / b == 1) {
            int r = a%b;
            a = b;
            b = r;
            cnt++;
            //debug(a, b, a / b, cnt);
            if (b == 0) break;
        }
        if (cnt%2) puts("Ollie wins");
        else puts("Stan wins");
    }
}
