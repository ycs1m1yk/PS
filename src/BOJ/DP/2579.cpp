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

using namespace std;
const int MAX = 301;

/*
    case | N-2 | N-1 |  N
     0     0     1     1
     1     1     0     1
     2     0     1     0
     3     1     1     0
*/
int N, stair[MAX], cache[MAX][4];

int main()
{
    memset(cache, -1, sizeof(cache));
    scanf("%d", &N);
    for (int i = 1; i < N + 1; i++)
    {
        scanf("%d", stair + i);
    }
    int result = 0;

    cache[1][0] = stair[1];
    cache[1][1] = stair[1];
    cache[1][2] = 0;
    cache[1][3] = 0;

    cache[2][0] = stair[2] + stair[1];
    cache[2][1] = stair[2];
    cache[2][2] = stair[1];
    cache[2][3] = stair[1];

    if (N == 1)
    {
        result = stair[1];
    }
    if (N == 2)
    {
        result = stair[2] + stair[1];
    }
    if (N > 2)
    {
        for (int pos = 3; pos < N + 1; pos++)
        {
            cache[pos][0] = stair[pos] + cache[pos - 1][1];
            cache[pos][1] = stair[pos] + max(cache[pos - 1][2], cache[pos - 1][3]);
            cache[pos][2] = cache[pos - 1][1];
            cache[pos][3] = cache[pos - 1][0];

            if (pos == N - 1)
            {
                cache[pos][0] = INT_MIN; // N-2, N-1밟으면 마지막 N을 못밟음
                cache[pos][1] = stair[pos] + max(cache[pos - 1][2], cache[pos - 1][3]);
                cache[pos][2] = cache[pos - 1][1];
                cache[pos][3] = cache[pos - 1][0];
            }
            if (pos == N)
            {
                cache[pos][0] = stair[pos] + cache[pos - 1][1];
                cache[pos][1] = stair[pos] + max(cache[pos - 1][2], cache[pos - 1][3]);
            }
        }
        result = max(cache[N][0], cache[N][1]);
    }

    printf("%d", result);
}