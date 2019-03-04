def combination(n: int) -> list:
    c = []
    for i in range(1<<n):
        if i == 0:
            continue
        l = []
        for j in range(n):
            if i&(1<<j) != 0:
                l.append(j+1)
        c.append(l)
    return c

