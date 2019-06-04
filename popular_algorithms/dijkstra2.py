from collections import defaultdict
from heapq import heappush, heappop

class Graph(object):
    """隣接リストによる有向グラフ"""

    def __init__(self):
        self.graph = defaultdict(list)
    
    def __len__(self):
        return len(self.graph)
        
    def add_edge(self, src, dst, weight=1):
        self.graph[src].append((dst, weight))
    
    def get_nodes(self):
        return self.graph.keys()
    
class Dijkstra(object):
    """ダイクストラ法"""

    def __init__(self, graph, start):
        # グラフ
        self.g = graph.graph
        # startノードからの最短距離
        self.dist = defaultdict(lambda: float('inf'))
        self.dist[start] = 0
        # 最短経路での1つ前のノード
        self.prev = defaultdict(lambda: None)
        # startノードをQに入れる
        self.Q = []
        heappush(self.Q, (self.dist[start], start))

        while self.Q:
            dist_u, u = heappop(self.Q)
            if self.dist[u] < dist_u:
                continue
            for v, weight in self.g[u]:
                alt = dist_u + weight
                if self.dist[v] > alt:
                    self.dist[v] = alt
                    self.prev[v] = u
                    heappush(self.Q, (alt, v))
    
    def shortest_dist(self, goal):
        return self.dist[goal]

    def shortest_path(self, goal):
        path = []
        node = goal
        while node is not None:
            path.append(node)
            node = self.prev[node]
        return path[::-1]

def main():
    inputs = [(0, 1, 5), (0, 2, 4), (0, 3, 2), (1, 2, 2), (1, 5, 6), (2, 3, 3),
            (2, 4, 2), (3, 4, 6), (4, 5, 4)]

    g = Graph()
    for src, dst, weight in inputs:
        g.add_edge(src, dst, weight)
        g.add_edge(dst, src, weight)

    d = Dijkstra(g, 0)
    print('最短経路: {}'.format(d.shortest_path(5)))
    print('最短距離: {}'.format(d.shortest_dist(5)))

if __name__ == '__main__':
    main()