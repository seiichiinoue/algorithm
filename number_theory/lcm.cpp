#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b==0) return a;
    else return gcd(b, a%b);
}

int lcm(int a, int b) {
    int g = gcd(a, b);
    return a / g * b;
}

int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i=0; i<n; ++i) cin >> v[i];
    
    if (n==2) {
        cout << lcm(v[0], v[1]) << endl;
    } else {
        int l = lcm(v[0], v[1]);
        for (int i=2; i<n; ++i) {
            l = lcm(l, v[i]);
        }
        cout << l << endl;
    }
}