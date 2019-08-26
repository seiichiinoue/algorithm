#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b==0) return a;
    else return gcd(b, a%b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i=0; i<n; ++i) cin >> v[i];
    
    if (n==2) {
        cout << gcd(v[0], v[1]) << endl;
        cout << lcm(v[0], v[1]) << endl;
    } else {
        int g = gcd(v[0], v[1]);
        int l = lcm(v[0], v[1]);
        for (int i=2; i<n; ++i) {
            g = gcd(g, v[i]);
            l = lcm(l, v[i]);
        }
        cout << g << endl;
        cout << l << endl;
    }
}