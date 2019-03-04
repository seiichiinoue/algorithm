n = 32

def fib(n):
    if n <= 1:
        return n
    return fib(n - 1) + fib(n - 2)

memo = [0] * (n + 1)
def fib_dp(n):
    if n <= 1:
        return n
    if memo[n] != 0:
        return memo[n] 
    else:
        memo[n] = fib(n - 1) + fib(n - 2)
        return memo[n]

if __name__ == '__main__':
    print(fib_dp(n))