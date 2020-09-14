#include<bits/stdc++.h>
using namespace std;
using point = pair<double,double>;
#define x first
#define y second
#define eps 1e-5
//#include "debugger.cpp"

class Line
{
public:
    double a, b, c; //ax + by = c;
    Line(point p, point q)
    {
        a = p.y - q.y;
        b = p.x - q.x; b = -b;
        c = - p.y * b - p.x * a;
    }
    void rotateLine(point p)
    {
        double _a, _b, _c;
        _a = b;
        _b = -a;
        _c = _a * p.x + _b * p.y;
        a = _a; b = _b; c = _c;
    }
    point intersect(Line p)
    {
        //debug(this->a , this->b, this->c);
        double X = (this->b * p.c - p.b * this->c) / (this->a * p.b - p.a * this->b);
        double Y = (this->c * p.a - p.c * this->a) / (this->a * p.b - p.a * this->b);
        return {-X, -Y};
    }
};

signed main()
{
    //freopen("input.txt", "r", stdin);
    point p, q, r;
    while (cin >> p.x >> p.y >> q.x >> q.y >> r.x >> r.y) {
        Line a(p, q);
        Line b(q, r);
        a.rotateLine({(p.x + q.x) / 2.0, (p.y + q.y) / 2.0});
        b.rotateLine({(r.x + q.x) / 2.0, (r.y + q.y) / 2.0});
        p = a.intersect(b);
        double dist = sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));
        //debug((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));
        //debug(p.x, p.y, dist, q.x, q.y);
        double cir = 2.0 * 3.141592653589793 * dist;
        cout << setprecision(2) << fixed << cir << "\n";
    }
}
