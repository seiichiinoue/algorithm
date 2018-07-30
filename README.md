## procon

## 素因数分解
factorizer.py

## ダイクストラ法
dijkstra.py

#### ダイクストラ法とは
[ダイクストラ法](https://ja.wikipedia.org/wiki/%E3%83%80%E3%82%A4%E3%82%AF%E3%82%B9%E3%83%88%E3%83%A9%E6%B3%95) (Dijkstra's Algorithm) は最短経路問題を効率的に解くグラフ理論におけるアルゴリズム．スタートノードからゴールノードまでの最短距離とその経路を求めることができる．

#### 最短経路問題
以下のようなグラフにおける最短経路を考える．

<img src="http://cdn-ak.f.st-hatena.com/images/fotolife/k/kuuso1/20151213/20151213071247.png" width="50%">

- 青丸をノード，緑線をエッジと呼ぶ．頂点間の移動には辺上の数字分のコストがかかる．その時の始点から終点までの最短経路を求める．
- ダイクストラ法のアルゴリズムは，始点から各ノードへの最短経路を効率よく探索して決定し，[最適性原理](http://www.msi.co.jp/nuopt/glossary/term_f5a4fc8856e71f6ca220d1baf48b73b58a2bc1e7.html)に基づいて終点までの最短経路を決定するもの．

#### 手順
- 初期化
	- ノードからのコストを格納したリスト ; route_list
	- 始点からの最短距離リスト ; minimum_distances_from_startnode
	- 未確定リスト ; unfixed_nodes
	- 各ノードにたどり着く最短経路における直前の確定したノード ; previous_fixed_nodes

- 各ノードまでの最短距離の決定
- 以下の処理を未確定ノードに対して行う
	- possible_dist; 始点からの仮の最短距離を格納する変数の宣言
	- possible_distの更新，決定
	- possible_distが現在格納されている始点からの最短距離よりも短ければ，始点からの最短距離をpossible_distに更新．
	- possible_distが最小の点を選択し，そのエッジで接続しているノードの最短距離を更新
	- 最短距離が決定したら，その直前のノードをprevious_fixed_nodesに格納