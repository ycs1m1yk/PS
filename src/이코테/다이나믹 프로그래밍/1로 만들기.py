import time
MAX = 30000
cache = [0]*MAX


def make_one(x):
    ret = cache[x]
    if x == 1:
        return 0
    if ret != 0:
        return ret

    ret = make_one(x-1) + 1
    if(x % 5 == 0):
        ret = min(ret, make_one(x//5)+1)
    elif(x % 3 == 0):
        ret = min(ret, make_one(x//3)+1)
    elif(x % 2 == 0):
        ret = min(ret, make_one(x//2)+1)

    return ret


x = int(input())

start_time = time.time()
print(make_one(x))

elapsed_time = time.time() - start_time
print(f"elapsed time: {elapsed_time:.4f}s")
