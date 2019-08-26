#include <bits/stdc++.h>
#define MAX 10000007
using namespace std;
typedef long long ll;

int dp[MAX][MAX];

int levenshtein(string a, string b) {
    for (int i=0; i<=a.size(); ++i) dp[i][0] = i;
    for (int i=0; i<=b.size(); ++i) dp[0][i] = i;
    
    for (int i=1; i<=a.size(); ++i) {
        for (int j=1; j<=b.size(); ++j) {
            int cost;
            if (a[i-1]==b[i-1]) cost = 0;
            else cost = 1;
            dp[i][j] = min({
                dp[i - 1][j] + 1,
                dp[i][j - 1] + 1,
                dp[i - 1][j - 1] + cost
            });
        }
    }
    return dp[a.size()][b.size()];
}

int main() {
    string a, b;
    cin >> a >> b;
    int ret;
    ret = levenshtein(a, b);
    cout << ret << endl;
    return 0;
}