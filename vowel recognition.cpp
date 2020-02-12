#include<cstdio>
#include<cstring>
using namespace std;

bool vowel(char a)
{
    return (a=='A'||a=='a'||a=='E'||a=='e'||a=='I'||a=='i'||a=='O'||a=='o'||a=='U'||a=='u');
}

void subStr(char a[])
{
    int len = strlen(a);
    int n = len - 1;
    long long s1, s2;
    s1 = s2 = 0;
    for (int i = 1; n >= 0; i++, n--) {
        if (vowel(a[n])) {
            s1 += i;
        }
    }
    n = len;
    for (int i = 0; i < len; i++, n--) {
        if (vowel(a[i])) {
            s2 += s1;
            s1 -= n;
        }
        else {
            s2 += s1;
        }
    }
    printf("%lld\n", s2);
}

int main()
{
    int t;
    char a[100005];
    scanf("%d", &t);

    while (t--) {
        scanf("%s", a);
        subStr(a);
    }
}
