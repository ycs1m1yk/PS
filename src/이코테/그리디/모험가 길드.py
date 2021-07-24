import sys

n = int(input())
players = list(map(int, sys.stdin.readline().rstrip().split()))
players.sort(reverse=True)

grouped = 0
answer = 0
while True:
    grouped += players[grouped]
    answer += 1
    if grouped == n:
        break

print(answer)
