#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; ++i)
using namespace std;

struct UnionFind {
    vector<int> par;
    
    UnionFind(int N) : par(N) {
        rep(i, N) par[i] = i;
    }
    
    int root(int x) {
        if (par[x]==x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx==ry) return;
        par[rx] = ry;
    }

    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main() {
    int N, Q; cin >> N >> Q;
    UnionFind tree(N);
    rep(i, Q) {
        int p, x, y;
        cin >> p >> x >> y;
        if (p==0) {
            tree.unite(x, y);
        } else {
            if (tree.same(x, y)) cout << "yes" << endl;
            else cout << "no" << endl;
        }
    }
    return 0;
}
