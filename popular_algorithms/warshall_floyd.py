def warshall_floyd(d, n):
    # d[i][j] = iからjへの最短距離
    for k in range(n):
        for i in range(n):
            for j in range(n):
                d[i][j] = min(d[i][j], d[i][k] + d[k][j])

    return d

def main():
    n, w = map(int, input().split())
    d = [[float('inf') for _ in range(n)] for _ in range(n)]
    for i in range(w):
        x, y, z = map(int, input().split())
        d[x][y] = z
        d[y][x] = z
    for i in range(n):
        d[i][i] = 0
    print(warshall_floyd(d, n))

if __name__ == '__main__':
    main()

# ------------
# sample input
# ------------
"""
7 10
0 1 2
0 2 5
1 2 4
2 3 2
1 3 6
1 4 10
3 5 1
4 5 3
4 6 5
5 6 9
"""
