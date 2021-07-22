# %%
n, m, k = map(int, input().split())
data = list(map(int, input().split()))
data.sort(reverse=True)

first = data[0]
second = 0
first_cnt = 0
for i in range(len(data)):
    if data[i] == first:
        first_cnt += 1
    else:
        second = data[i]
        break

cycle = k*first_cnt+1
cycle_sum = (cycle-1)*first+second
answer = (m//cycle)*cycle_sum + (m % cycle)*first
print(answer)
