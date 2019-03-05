"""
sample input:
3
2
1
3
0
2
620

expected output:
6
"""


V = [1,5,10,50,100,500]
C = [int(input()) for _ in range(6)]
A = int(input())

ans = 0
for i in range(len(V) - 1, -1, -1):
    t = min(A // V[i], C[i])
    A -= t * V[i]
    ans += t
print(ans)

    