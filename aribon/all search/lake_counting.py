"""
Task:
    8近傍のにある水たまりは繋がっている．水たまりはいくつあるか．

solution:
    深さ優先探索．
    適当なWから始めて繋がっている部分を全て.に置き換えていくという一連の作業，
    Wがなくなるまでやって，それが何回行われるかで判定する

sample input:
10 12
W........WW.
.WWW.....WWW
....WW...WW.
.........WW.
.........W..
..W......W..
.W.W.....WW.
W.W.W.....W.
.W.W......W.
..W.......W.

expected output:
3
"""

# --------
# solution
# --------

N, M = map(int, input().split())
field = [list(input()) for _ in range(N)]

def dfs(x, y):  # 現在位置x,y
    # 現在地を.に変える
    field[x][y] = '.'

    for dx in range(-1, 2, 1):
        for dy in range(-1, 2, 1):
            nx, ny = x + dx, y + dy
            # 庭の範囲内かの判定と，水たまりかの判定
            if  (0 <= nx and nx < N) and (0 <= ny and ny < M) and (field[nx][ny] == 'W'):
                dfs(nx, ny)
    return

def solve():
    res = 0
    for i in range(N):
        for j in range(M):
            if field[i][j] == 'W':
                dfs(i, j)
                res += 1
    print(res)

if __name__ =='__main__':
    solve()