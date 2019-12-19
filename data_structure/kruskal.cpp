#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; ++i)
#define MAX_E (long long)1e5
using namespace std;

struct UnionFind {
    /* N: 0-indexed array size */
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

struct edge{ int u, v, cost; };

bool comp(const edge &e1, const edge &e2) {
    return e1.cost < e2.cost;
}

edge es[MAX_E];
int V, E;

int kruskal() {
    sort(es, es+E, comp);
    UnionFind tree(V);
    int res = 0;
    rep(i, E) {
        edge e = es[i];
        if (!tree.same(e.u, e.v)) {
            tree.unite(e.u, e.v);
            res += e.cost;
        }
    }
    return res;
}