#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; ++i)
using namespace std;

struct UnionFind {
    /* N: 0-indexed array size */
    vector<int> par;
    vector<int> _size;
    
    UnionFind(int N) : par(N), _size(N) {
        rep(i, N) par[i] = i;
        rep(i, N) _size[i] = 1;
    }
    
    int root(int x) {
        if (par[x]==x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx==ry) return;
        if (_size[rx] <= _size[ry]) swap(rx, ry);
        _size[rx] += _size[ry];
        par[ry] = rx;
    }

    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }

    int size(int x) {
        return _size[root(x)];
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
