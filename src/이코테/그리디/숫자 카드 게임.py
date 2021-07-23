import sys
n, m = map(int, input().split())

answer = 0
for _ in range(n):
    row_min = 0
    data = sys.stdin.readline().rstrip()
    current_row = list(map(int, data.split()))

    current_row.sort()
    row_min = current_row[0]
    answer = max(row_min, answer)

print(answer)
