'''
    ** -1 연산이 많은 case 고려하기

    n=143, k=12

    143->132->11->1
      +11   +1  +10
'''
n, k = map(int, input().split())

answer = 0
while n > 1:
    if(n % k == 0):
        n /= k
        answer += 1
    else:
        answer += n-(n//k)*k
        n -= n-(n//k)*k
        if n == 0:
            answer -= 1

print(int(answer))
