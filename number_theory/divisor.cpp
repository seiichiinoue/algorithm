#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> calc_divisor(ll n) {
    vector<ll> res;
    for (long long i=1LL; i*i<=n; ++i) {
        if (n%i==0) {
            res.push_back(i);
            ll j = n / i;
            if (j != i) res.push_back(j);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> div = calc_divisor(M);
    
    // M の約数 d であって、d * N <= M となる最大の d を求める
    ll res = 1;
    for (auto d : div) {
        if (d * N <= M) res = max(res, d);
    }
    cout << res << endl;
}