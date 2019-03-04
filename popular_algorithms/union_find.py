class UnionFind:
    def __init__(self, n):
        self.par = [-1 for _ in range(n)]

    def root(self, x):
        """return index of element x's root"""
        if self.par[x] < 0:
            return x
        self.par[x] = self.root(self.par[x])
        return self.par[x]

    def size(self, x):
        """return size of group x belong to"""
        return -self.par[self.root(x)]

    def check_join(self, x, y):
        x, y = self.root(x), self.root(y)
        return True if x == y else False
    
    def marge(self, x, y):
        """marge group x belong to and that y belong to.
        Args:
            x, y: the elements of group you want to marge
        Return:
            boolean: if able to marge, return True, else False
        """
        x, y = self.root(x), self.root(y)
        if x == y:
            return False
        if self.size(x) < self.size(y):
            x, y = y, x
        self.par[x] += self.par[y]
        self.par[y] = x
        return True

# -----------------------------------------------------
# solution of atcoder typical contest 001 B: union find
# -----------------------------------------------------

def main():
    ans = []
    N, Q = map(int, input().split())
    # initialize unionfind object
    uf = UnionFind(N)
    for _ in range(Q):
        p, a, b = map(int, input().split())
        if p == 0:  # marge query
            uf.marge(a, b)
            print(uf.par)
        elif p == 1:
            ans.append('Yes' if uf.check_join(a, b) else 'No')
    return ans

if __name__ == '__main__':
    print('\n'.join(main()))

"""
sample input:
8 9
0 1 2
0 3 2
1 1 3
1 1 4
0 2 4
1 4 1
0 4 2
0 0 0
1 0 0

expected output:
Yes
No
Yes
Yes
"""