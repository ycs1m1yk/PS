# %%
'''
    시간복잡도 O(N^1), O(N^2), O(NlogN), O(N^3)인 반복문으로
    50,000,000 ~ 100,000,000 정도의 연산량의 수행시간을 측정한다.
'''
from math import log
from random import randint
import time

exp = int(input())
end = int((10**8)**(1/exp))
n = randint(end//2, end)

start_time = time.time()
print(f"### time complexity: O(N^{exp:,}), N = {n:,}, N^{exp:,} = {n**exp:,}")

sum = 0
# O(N^1)
if(exp == 1):
    for _ in range(n):
        sum += 1
# O(N^2)
if(exp == 2):
    for _ in range(n):
        for _ in range(n):
            sum += 1
# O(N^3)
if(exp == 3):
    for _ in range(n):
        for _ in range(n):
            for _ in range(n):
                sum += 1


elapsed_time = time.time() - start_time
print(f"sum = {sum:,}")
print(f"##elapsed time: {elapsed_time:.6f}s")

# %%
end = 10**7
n = randint(end//2, end)

start_time = time.time()
print(f"    ###time complexity: O(NlogN), N = {n:,}, NlogN = {n*log(n, 10):,}")

sum = 0
# O(NlogN)
for _ in range(n):
    for _ in range(int(log(n))):
        sum += 1

elapsed_time = time.time() - start_time
print(f"sum = {sum:,}")
print(f"##elapsed time: {elapsed_time:.6f}s")
