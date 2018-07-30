
# dijkstra algorithms
# coding: utf-8


import math


# グラフ構造を配列で表記; 初期化
route_list = [[0, 4, 5, 0, 2, 0, 0], [4, 0, 6, 4, 3, 0, 0], [5, 6, 0, 6, 0, 0, 10],
              [0, 4, 6, 0, 6, 2, 6], [2, 3, 0, 6, 0, 9, 0], [0, 0, 0, 2, 9, 0, 3], [0, 0, 10, 6, 0, 3, 0]]


# ルート探索
def route(previous_fixed_nodes=list, start_node=int):
	destinations = [i for i in range(len(previous_fixed_nodes))]
	del destinations[start_node]
	min_routes = list()
	for destination in destinations:
		min_route = list()
		previous_node = destination

		while previous_node != -1:
		    if previous_node !=0:
		        min_route.append(previous_node)
		    else:
		        min_route.append(previous_node)
		    previous_node = previous_fixed_nodes[previous_node]
		min_route = min_route[::-1]
		min_routes.append(min_route)

	return min_routes



# ダイクストラ法
def dijkstra(route_list=list, start_node=int):
    # 初期化
	route_list = route_list  # グラフ
	node_num = len(route_list)  # ノード数
	start_node = start_node  # 始点となるノードのindex

	minimum_distances_from_startnode = [math.inf] * node_num  
	minimum_distances_from_startnode[start_node] = 0  # 始点から各ノードまでの最短距離
	unfixed_nodes = list(range(node_num))  # 未確定リスト
	previous_fixed_nodes = [-1] * node_num  # 初期値はマイナスとして，各ノードにたどり着く最短経路において直前の確定したノードを格納する


	while len(unfixed_nodes) != 0:  # 全ての最短経路が判明するまで
		dist_temp = math.inf
		min_distance_node = 0

		# 各ノードまでの最短距離の更新
		for node_index in unfixed_nodes:
			if node_index == start_node:
				dist_temp = 0
				min_distance_node = start_node

			if dist_temp > minimum_distances_from_startnode[node_index]:
				dist_temp = minimum_distances_from_startnode[node_index]
				min_distance_node = node_index

		min_distance_node_edges = route_list[min_distance_node]

		for i, min_distance_node_edge in enumerate(min_distance_node_edges):
			if min_distance_node_edge == 0:
				continue

			else:
				if minimum_distances_from_startnode[i] > min_distance_node_edge + minimum_distances_from_startnode[min_distance_node]:
					minimum_distances_from_startnode[i] = min_distance_node_edge + minimum_distances_from_startnode[min_distance_node]
					previous_fixed_nodes[i] = min_distance_node

		unfixed_nodes.remove(min_distance_node)

	r = route(previous_fixed_nodes=previous_fixed_nodes, start_node=start_node)

	return r  # 各ノードへの最短経路のリストを返す


if __name__ == '__main__':
	min_list = dijkstra(route_list=route_list, start_node=0)

	for index, l in enumerate(min_list):
		print("{}への最短経路: {}".format(index + 1, l))


