#include <bits/stdc++.h>
using namespace std;
#define INF 1e+9
#define MAX_V 10
#define rep(i,n) for(int i=0; i<n; ++i)
typedef pair<int, int> P;

struct edge {
    int to;
    int cost;
};

int V;
vector<edge> G[MAX_V];
int d[MAX_V];

void dijkstra(int s) {
    priority_queue<P, vector<P>, greater<P>> que;
    fill(d, d+V, INF);
    d[s] = 0;
    que.push(P(0, s));

    while(!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        rep(i, G[v].size()) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}

int main() {
    int start = 0;
    cin >> V;
    int E; cin >> E;
    rep(i, E) {
        int a, b, c;
        cin >> a >> b >> c;
        edge e = {b, c};
        G[a].push_back(e);
    }
    dijkstra(start);
    rep(i, V) {
        if (d[i] != INF)
        cout << "cost from " << start << " to " << i << ": " << d[i] << endl; 
    }
}