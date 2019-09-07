#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; ++i)
typedef long long ll;

// 尺取り法
int main() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll ans = 0, sum=0;
    int r = 0;
    rep(i, n) {
        while (sum < k) {
            if (r==n) break;
            else {
                sum += a[r];
                r++;
            }
        }
        if (sum < k) break;
        ans += n-r+1;
        sum -= a[i];
    }
    cout << ans << endl;
    return 0;
}