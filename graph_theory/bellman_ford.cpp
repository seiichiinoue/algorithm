#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; ++i)

struct Edge {
    int to, cost;
    Edge(int to, int cost) : to(to), cost(cost) {}
};

typedef vector<vector<Edge>> AdjList;   // 隣接グラフ
AdjList graph;

const int INF = 100000000;
vector<int> dist;

bool bellman_ford(int n, int s) {
    dist = vector<int>(n, INF);
    dist[s] = 0;
    rep(i, n) {
        rep(v, n) {
            rep(k, n) {
                Edge e = graph[v][k];
                if (dist[v] != INF && dist[e.to] > dist[v] + e.cost) {
                    dist[e.to] = dist[v] + e.cost;
                    if (i==n-1) return true;    // n回目にも更新があるなら負の経路が存在
                }
            }
        }
    }
    return false;
}

int main() {
    int n, m; cin >> n >> m;
    graph = AdjList(n);
    rep(i, m) {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back(Edge(to, cost));
    }
    bellman_ford(n, 0);

    for (int i=1; i<n; ++i) {
        if (dist[i] != INF) {
            cout << "cost from 0 to " << i << ": " << dist[i] << endl;
        }
    }
}