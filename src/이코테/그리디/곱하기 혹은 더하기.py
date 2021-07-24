import sys

s = list(map(int, sys.stdin.readline().rstrip()))
answer = int(s[0])

if len(s) == 1:
    print(answer)
else:
    for i in range(1, len(s)):
        answer = max(answer+s[i], answer*s[i])

    print(answer)
