#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> c;

int main() {
    int n; cin >> n;
    for (int i=0; i<(1<<n); ++i) {
        if (i==0) continue;
        vector<int> v;
        for (int j=0; j<n; ++j) {
            if (i&(1<<j)) v.push_back(j+1);
        }
        c.push_back(v);
    }
    for (int i=0; i<c.size(); ++i) {
        for (int j=0; j<c[i].size(); ++j) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
}