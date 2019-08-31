#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

vector<P> factorizer(ll n) {
    vector<P> facts;
    for (ll p=2; p*p<=n; ++p) {
        if (n % p != 0) continue;
        int num = 0;
        while (n % p == 0) { ++num; n /= p; }
        facts.push_back(P(p, num));
    }
    if (n != 1) facts.push_back(P(n, 1));
    return facts;
}

int main() {
    int n; cin >> n;
    auto res = factorizer(n);
    for (auto prime_exp : res) {
        cout << prime_exp.first << ": " << prime_exp.second << endl;
    }
}