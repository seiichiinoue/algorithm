n, r = map(int, input().split())
l = [list(map(int, input().split())) for _ in range(r)]

"""
グラフ入力は次の形に対応．
[dep_i dst_i weight_i]
"""
from collections import defaultdict
class Graph(object):
    """隣接リストによる有向グラフ"""

    def __init__(self):
        self.graph = defaultdict(list)
    
    def __len__(self):
        return len(self.graph)
    
    def add_edge(self, src, dst, weight=1):
        self.graph[src] = []
        self.graph[src].append((dst, weight))
    
    def get_nodes(self):
        return self.graph.keys()

g = Graph()
for s, d, w in l:
    g.add_edge(s - 1, d - 1, w)
    g.add_edge(d - 1, s - 1, w)
g = g.graph
from heapq import heappop, heappush
dist = [float('inf')] * n
dist[0] = 0
prev = [None] * n
que = []
def dijkstra():
    heappush(que, (0, 0))
    while que:
        dist_u, u = heappop(que)
        if dist[u] < dist_u:
            continue
        for v, w in g[u]:
            alt = dist_u + w
            if dist[v] > alt:
                dist[v] = alt
                prev[v] = u
                heappush(que, (alt, v))
dijkstra()
print(dist)
print(g)
    