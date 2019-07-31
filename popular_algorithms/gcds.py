from functools import reduce

def gcd(a,b):
    if b == 0:
        return a
    else:
        return gcd(b, a%b)

def gcds(*numbers):
    return reduce(gcd, numbers)

if __name__ == '__main__':
    print(gcds(*[int(i) for i in input().split()]))
    
