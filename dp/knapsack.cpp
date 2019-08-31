#include <bits/stdc++.h>
using namespace std;
#define MAX_N 10000
#define MAX_W 10000

int n, W;
int w[MAX_N], v[MAX_N];
int dp[MAX_N+1][MAX_W+1];

int rec(int i, int j) {
    if (dp[i][j] >= 0) return dp[i][j];
    int res;
    if (i == n) {
        res = 0;   
    } else if (j < w[i]) {
        res = rec(i+1, j);
    } else {
        res = max(rec(i+1, j), rec(i+1, j-w[i])+v[i]);
    }
    return dp[i][j] = res;
}

int main() {
    cin >> n >> W;
    for (int i=0; i<n; ++i) cin >> w[i];
    for (int i=0; i<n; ++i) cin >> v[i];
    memset(dp, -1, sizeof(dp));
    cout << rec(0, W) << endl;
}