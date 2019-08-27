#include <bits/stdc++.h>
#define INF 100000000
#define rep(i,n) for(int i=0; i<n; ++i)
using namespace std;

typedef vector<vector<int>> M; M dp;

int warshall_floyd(int n) {
    rep(k,n) {
        rep(i,n) {
            rep(j,n){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    return 0;
}

int main() {
    int n, w; cin >> n >> w;
    dp = M(n, vector<int>(n, INF));
    rep(i,n) {
        rep(j,n){
            dp[i][j] = INF;
        }
    }
    rep(i,n) dp[i][i] = 0;
    rep(i,w) {
        int x, y, z;
        cin >> x >> y >> z;
        dp[x][y] = z;
        // dp[y][x] = z; // 有向グラフなら消す
    }
    warshall_floyd(n);
    rep(i, n) {
        rep(j, n) {
            if (i != j && dp[i][j] != INF)
            cout << "cost from " << i << " to " << j << ": " << dp[i][j] << endl;
        }
    }
    return 0;
}