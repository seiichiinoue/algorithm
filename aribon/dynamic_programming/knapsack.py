"""
Tasks:
knapsack問題，重さと価値がそれぞれw,vの品物がある．
総重量がWを超えないように選ぶときの価値の最大値はいくつか．

sample input:
n W
w_n, v_n

4 5
2 3
1 2
3 4
2 2

expected output:
7
"""

n, W = map(int, input().split())
w, v = [], []
for _ in range(n):
    a, b = map(int, input().split())
    w.append(a)
    v.append(b)

# -----------------------
# solution with recursion
# -----------------------

memo = [[-1] * (W + 1) for _ in range(n + 1)]
def dp(i, j):
    if memo[i][j] >= 0:
        return memo[i][j]
    if i == n:
        res = 0
    elif j < w[i]:
        res = dp(i + 1, j)
    else:
        res = max(dp(i + 1, j), dp(i + 1, j - w[i]) + v[i])
    memo[i][j] = res
    return res
def solve():
    print(dp(0, W))

# ------------------
# solution with loop
# ------------------
memo2 = [[-1] * (W + 1) for _ in range(n + 1)]
def loop():
    for i in range(n-1, -1, -1):
        for j in range(0, W+1, 1):
            if j < w[i]:
                memo2[i][j] = memo2[i + 1][j]
            else:
                memo2[i][j] = max(memo[i + 1][j], memo2[i + 1][j - w[i]] + v[i])
    print(memo2[0][W])


if __name__ == "__main__":
    solve()
    loop()
