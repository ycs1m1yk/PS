import time
from random import randint
MAX_SIZE = 1000
cache = [0]*MAX_SIZE


def fibonacci(x):
    if x == 1 or x == 2:
        return 1
    if cache[x] != 0:
        return cache[x]

    cache[x] = fibonacci(x-1) + fibonacci(x-2)
    return cache[x]


start_time = time.time()
n = randint(1, 999)
print(f"fibonacci({n}) = {fibonacci(n):,}")

elapsed_time = time.time() - start_time
print(f"elapsed time: {elapsed_time:.4f}s\n")
