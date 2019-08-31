#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    vector<P> facts;
    int n; cin >> n;
    int base=2, exp=0;
    while (base*base<=n) {
        while (n%base==0) {
            n /= base; exp++;
        }
        if (exp>0) {
            facts.push_back(make_pair(base, exp));
        }
        base++; exp=0;
    }
    if (n>1) facts.push_back(make_pair(n,1));
    
    for (int i=0; i<facts.size(); i++) {
        cout << facts[i].first << " " << facts[i].second << endl;
    }
}