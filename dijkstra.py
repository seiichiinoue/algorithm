
# グラフ構造を配列で表記; 初期化
route_list = [[0, 5, 4, 2, 0, 0], [5, 0, 2, 0, 0, 6], [4, 2, 0, 3, 2, 0],
              [2, 0, 3, 0, 6, 0], [0, 0, 2, 6, 0, 4], [0, 6, 0, 0, 4, 0]]


import math

def dijkstra():
    # 初期化
	node_num = len(route_list)  # ノード数
	start_node = 0  # 始点となるノードのindex
	end_node = 5

	minimum_distances_from_startnode = [math.inf] * node_num  
	minimum_distances_from_startnode[start_node] = 0  # 始点から各ノードまでの最短距離
	unfixed_nodes = list(range(node_num))  # 未確定リスト
	previous_fixed_nodes = [-1] * node_num  # 初期値はマイナスとして，各ノードにたどり着く最短経路において直前の確定したノードを格納する


	while len(unfixed_nodes) != 0:  # 全ての最短経路が判明するまで
		possible_min_distance_from_startnode = math.inf
		min_distance_node = 0

		# 各ノードまでの最短距離の更新
		for node_index in unfixed_nodes:
			if node_index == start_node:
				possible_min_distance_from_startnode = 0
				min_distance_node = start_node

			if possible_min_distance_from_startnode > minimum_distances_from_startnode[node_index]:
				possible_min_distance_from_startnode = minimum_distances_from_startnode[node_index]
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

	min_route = list()
	previous_node = node_num - 1
	while previous_node != -1:
	    if previous_node !=0:
	        min_route.append(previous_node)
	    else:
	        min_route.append(previous_node)
	    previous_node = previous_fixed_nodes[previous_node]

	min_route = min_route[::-1]

	return min_route



print(dijkstra())




























