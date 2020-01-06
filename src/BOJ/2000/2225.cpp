#include <iostream>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <deque>
#include <queue>
#include <stack>
#include <utility>
#include <vector>

/*
    ❗ 덧셈에 +0을 어느 자리에나 넣을 수 있다.

    1
    1+1/2
    1+1+1/1+2/2+1/3
    1+1+1+1/1+1+2/1+2+1/2+1+1/1+3/3+1/4
*/

using namespace std;
const int MAX = 201;
const int DIVISOR = 1000000000;

long long cache[MAX][MAX];

long long d(int N, int K)
{
    long long &ret = cache[N][K];
    if (K == 1)
        return ret = 1;
    if (N == 1)
        return ret = K;
    if (ret != -1)
        return ret;

    return ret = d(N - 1, K) % DIVISOR + d(N, K - 1) % DIVISOR;
}

int main()
{
    int N, K;
    memset(cache, -1, sizeof(cache));
    scanf("%d %d", &N, &K);
    cout << d(N, K) % DIVISOR;
}