import time
import sys


def dp(x):
    if x == 1:
        cache[x-1] = warehouses[0]
        return cache[x-1]
    if x == 2:
        cache[x-1] = warehouses[1]
        return cache[x-1]
    if x == 3:
        cache[x-1] = warehouses[0]+warehouses[2]
        return cache[x-1]
    if cache[x-1] != 0:
        return cache[x-1]

    cache[x-1] = max(dp(x-2)+warehouses[x-1], dp(x-3)+warehouses[x-1])
    return cache[x-1]


n = int(input())
cache = [0]*n
warehouses = list(map(int, sys.stdin.readline().rstrip().split()))

start_time = time.time()

dp(n)
dp(n-1)
print(cache)
cache.sort(reverse=True)
ans = cache[0]
print(ans)

elapsed_time = time.time() - start_time
print(f"elapsed time: {elapsed_time:.4f}s")
