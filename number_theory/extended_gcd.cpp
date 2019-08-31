#include <bits/stdc++.h>
using namespace std;

// 返り値: a と b の最大公約数
// ax + by = gcd(a, b) を満たす (x, y) が格納される
long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) { x = 1; y = 0; return a; }
    long long d = extGCD(b, a%b, y, x);
    y -= a/b * x;
    return d;
}

int main() {
    long long a, b; cin >> a >> b;
    long long x, y;
    extGCD(a, b, x, y);
    cout << x << " " << y << endl;
}