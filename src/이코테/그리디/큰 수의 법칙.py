# %%
n, m, k = map(int, input().split())
data = list(map(int, input().split()))
data.sort(reverse=True)

first = data[0]
second = data[1]

cycle = k+1
cycle_sum = (cycle-1)*first+second
answer = (m//cycle)*cycle_sum + (m % cycle)*first
print(answer)
