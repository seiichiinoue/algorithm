"""
sample input:
6
10
1 7 15 20 30 50
"""

N, R = [int(input()) for _ in range(2)]
X = [int(i) for i in input().split()]

def solve():
    X.sort()
    i = 0
    ans = 0
    while i < N:
        s = X[i]  # 一番左のカバーされていない点の位置
        while i < N and X[i] <= s + R:
            i += 1
        p = X[i - 1]
        while i < N and X[i] <= p + R:
            i += 1
        ans += 1
    print(ans)

if __name__ == '__main__':
    solve()
