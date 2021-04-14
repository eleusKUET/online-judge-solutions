#include<stdio.h>

int main()
{
    int a, b;
    while (scanf("%d %d", &a, &b) != EOF) {
        int mx = 0;
        int p = a, q = b;
        if (a > b) {
            int tmp = a;
            a = b;
            b = tmp;
        }

        for (int i = a; i <= b; i++) {
            int cnt = 0;
            int h = i;
            while (h > 1) {
                if (h%2 == 0) h /= 2;
                else h = 3 * h + 1;
                cnt++;
            }
            if (mx < cnt)
                mx = cnt;
        }
        printf("%d %d %d\n", p, q, mx + 1);
    }
}
