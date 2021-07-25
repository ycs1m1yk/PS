'''
    1 <= N <= 1,000
    nC0 + nC1 + ... + nCn-1 + nCn = 2^n
    => 동전들의 모든 조합의 경우를 구하면
       N=30만 되더라도 2^30 ~= 10^9, 시간초과
'''
import sys
import time
from itertools import combinations

n = int(input())
coins = list(map(int, sys.stdin.readline().rstrip().split()))

start_time = time.time()

prices = []
for r in range(1, len(coins)):
    pool = combinations(coins, r)
    for c in pool:
        local_sum = 0
        for e in c:
            local_sum += e
        prices.append(local_sum)

prices.sort()
answer = 1
for price in prices:
    if answer == price:
        answer += 1
    else:
        if answer < price:
            break

print(prices)
print(answer)
elapsed_time = time.time() - start_time
print(f"elapsed time: {elapsed_time:.6f}ms")
