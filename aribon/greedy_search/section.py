"""
sample input:
5
1 2 4 6 8 
3 5 7 9 10

expected output:
3
"""

n = int(input())
start =[int(i) for i in input().split()]
end = [int(i) for i in input().split()]

l = [[s,e] for s, e in zip(start, end)]
l.sort(key=lambda x: x[1])

ans, t = 0, 0
for i in range(n):
    if t < l[i][0]:
        ans += 1
        t = l[i][1]
print(ans)