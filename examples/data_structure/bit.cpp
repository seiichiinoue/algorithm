#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;

struct fenwick_tree {
    typedef int T;
    T n;
    vector<T> bit;

    // 各要素の初期値は 0 
    fenwick_tree(T num) : bit(num+1, 0) { n = num; }

    // a_i += w
    void add(T i, T w) {
        for (T x = i; x <= n; x += x & -x) {
            bit[x] += w;
        }
    }
    // [1, i] の和を計算.
    T sum(T i) {
        T ret = 0;
        for (T x = i; x > 0; x -= x & -x) {
            ret += bit[x];
        }
        return ret;
    }
    // [left+1, right] の和を計算.
    T sum(T left, T right) {
        return sum(right) - sum(left);
    }
};

int main() {
    int n; cin >> n;

    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(b.begin(), b.end());
    map<int, int> mp;

    for(int i = 0; i < n; i++) {
        mp[b[i]] = i+1;
    }

    fenwick_tree ft(n+1);

    ll ans = 0;

    for (int j = 0; j < n; j++) {
        ans += j - ft.sum(mp[a[j]]);
        ft.add(mp[a[j]], 1);
    }

    cout << ans << endl;

    return 0;
}
