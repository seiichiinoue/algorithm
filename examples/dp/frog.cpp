#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<n; ++i)
#define rep1(i, n) for (int i=1; i<=n; ++i)
#define INF (1e9)
using namespace std;
typedef long long ll;

int main() {
    ll n; cin >> n;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];
    vector<ll> dp(n, INF);
    dp[0] = 0;
    dp[1] = abs(h[0] - h[1]);
    for (int i=2; i<n; ++i) { 
        dp[i] = min(dp[i-1] + abs(h[i] - h[i-1]), dp[i-2] + abs(h[i] - h[i-2]));
    }
    cout << dp[n-1] << endl;
}