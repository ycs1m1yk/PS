'''
    백준 boj.kr/1439

    ** 백준 python3, pypy3 비교
        29200 KB	80 ms	Python 3 
        124504 KB	120 ms	PyPy3
'''
import sys

s = sys.stdin.readline().rstrip()
if(len(s) == 1):
    print(0)
else:
    cnt = 0
    prev = s[0]
    for i in range(1, len(s)):
        if s[i] != prev:
            cnt += 1
            prev = s[i]

    print(int((cnt+1)/2))
