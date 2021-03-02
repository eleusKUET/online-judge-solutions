#include "bits/stdc++.h"
using namespace std;
using dd = pair<double,double>;
#define x first
#define y second

struct Line {
    int a, b, c;
    Line(){}
    Line(int x1, int y1, int x2, int y2) {
        a = y2 - y1;
        b = -(x2 - x1);
        c = x1 * a + y1 * b;
    }
};

void intersect(Line a, Line b)
{
    int dx = a.c * b.b - a.b * b.c;
    int d = a.a * b.b - a.b * b.a;
    int dy = a.a * b.c - b.a * a.c;
    if (d == 0 && (dy || dx)) {
        puts("NONE");
    }
    else if (d == 0 && dy == 0 && dx == 0) {
        puts("LINE");
    }
    else {
        printf("POINT %0.2f %0.2f\n", dx * 1.0 / d, dy * 1.0 / d);
    }
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    puts("INTERSECTING LINES OUTPUT");
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        Line a(x1, y1, x2, y2);
        cin >> x1 >> y1 >> x2 >> y2;
        Line b(x1, y1, x2, y2);
        intersect(a, b);
    }
    puts("END OF OUTPUT");
}
