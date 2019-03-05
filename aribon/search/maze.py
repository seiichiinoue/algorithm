"""
Tasks:
    大きさN*Mの迷路が与えられる．
    迷路は通路と壁からできていて，1ターンで隣接する上下左右4マスの通路に移動できる．
    スタートからゴールまで移動するのに必要な最小のターン数を求めよ．

Solution:
    幅優先探索．


Sample input:
10 10
#S######.#
......#..#
.#.##.##.#
.#........
##.##.####
....#....#
.#######.#
....#.....
.####.###.
....#...G#

expected output:
22
"""

# --------
# solution
# --------

N, M = map(int, input().split())
INF = 10 ** 8
maze = [list(input()) for _ in range(M)]

start_x, start_y = 0, maze[0].index('S')
goal_x, goal_y = M - 1, maze[-1].index('G')

d = [[INF] * M for _ in range(N)]
dirction_x, direction_y = [1,0,-1,0], [0,1,0,-1]

print(d)

def bfs():
    que = []
    # 始めにスタート地点をqueにプッシュ
    que.append([start_x, start_y])
    d[start_x][start_y] = 0
    # queが空になるまでループ
    while True:
        # queの先頭から座標を取り出す
        p = que.pop(0)
        # print(que)
        if p[0] == goal_x and p[1] == goal_y:
            break

        for dx, dy in zip(dirction_x, direction_y):
            # 移動した後の点を(nx, ny)とする
            nx, ny = p[0] + dx, p[1] + dy
            # 移動可能か，すでに訪れたことがあるかの判定
            if (0 <= nx and nx < N) and (0 <= ny and ny < M) and (maze[nx][ny] != '#' and d[nx][ny] == INF):
                # 移動できるならqueに入れ，その点の距離をpからの距離+1で確定する
                que.append([nx, ny])
                d[nx][ny] = d[p[0]][p[1]] + 1
    return d[goal_x][goal_y]

def solve():
    res = bfs()
    print(res)

if __name__ == '__main__':
    solve()

