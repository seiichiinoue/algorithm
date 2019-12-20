#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// implementation of RMQ; Range Minimum Query
struct SegmentTree {
    const int MAX_N = 131072;
    
    int n;
    vector<int> dat;
    
    // initialize every node INT_MAX (min segtree)
    SegmentTree(int N) : n(N) {
        // 2n-1 nodes for array length n
        dat.resize(MAX_N * 4);
        for (int i = 0; i < 4 * n; i++) dat[i] = INT_MAX;
    }
    
    // for (n)th node...
    // parent  : (n-1)/2
    // children: 2n+1, 2n+2
    
    // update value of (i)th node to x
    void update(int i, int x) {
        // index of leaf node
        i += n - 1;
        dat[i] = x;
        
        // update while climbing up the tree
        while (i > 0) {
            i = (i - 1) / 2;
            dat[i] = min(dat[i * 2 + 1], dat[i * 2 + 2]);
        }
    }
    
    // return min of [a, b)
    // run like query(a, b, 0, 0, n)
    int query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return INT_MAX;
        if (a <= l && r <= b) return dat[k];
        
        int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
        int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
        return min(vl, vr);
    }
};


