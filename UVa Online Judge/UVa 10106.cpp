//UVA 10106
//Author: Eleus Ahammad
//CSE, KUET
#include<bits/stdc++.h>
using namespace std;
using BigInt  = vector<int>;

BigInt add(BigInt a, BigInt b)
{
    BigInt ans;
    if (a.size() < b.size()) swap(a, b);
    int car = 0, sum;
    for (int i = 0; i < b.size(); i++) {
        sum = a[i] + b[i] + car;
        ans.push_back(sum%10);
        car = sum / 10;
    }
    for (int i = b.size(); i < a.size(); i++) {
        sum = a[i] + car;
        ans.push_back(sum%10);
        car = sum / 10;
    }
    while (car) {
        ans.push_back(car%10);
        car /= 10;
    }
    return ans;
}

BigInt multiply(BigInt a, BigInt b)
{
    BigInt ans;
    int car, prod;
    if (a.size() > b.size()) swap(a, b);
    for (int i = 0; i < a.size(); i++) {
        car = 0;
        BigInt tmp(b.size());
        for (int j = 0; j < b.size(); j++) {
            prod = a[i] * b[j] + car;
            tmp[j] = prod % 10;
            car = prod / 10;
        }
        while (car) {
            tmp.push_back(car%10);
            car /= 10;
        }
        for (int j = 0; j < i; j++)
            tmp.emplace(tmp.begin(), 0);
        ans = add(ans, tmp);
    }
    return ans;
}

int main()
{
    string x, y;
    ios::sync_with_stdio(0);
    while (cin >> x >> y) {
        if (x.size() == 1 && x[0] == '0' || y.size() == 1 && y[0] == '0') {
            cout << "0\n";
            continue;
        }
        vector<int> a, b;
        for (int i = x.size() - 1; i >= 0; i--)
            a.push_back(x[i] - '0');
        for (int i = y.size() - 1; i >= 0; i--)
            b.push_back(y[i] - '0');
        a = multiply(a, b);

        for (int i = a.size() - 1; i >= 0; i--) {
            cout << a[i];
        }
        cout << "\n";
    }
}
