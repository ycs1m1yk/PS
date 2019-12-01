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
    왜 틀렸지?? -> 반례 찾아보자..
*/

using namespace std;
const int MAX = 100;

int N;
long long max1, sequence[MAX], cache[MAX];

long long maxSerialSum(int pos)
{
    long long &ret = cache[pos];
    if (pos == 1)
    {
        max1 = sequence[pos];
        return ret = sequence[pos];
    }
    if (ret != -1)
    {
        return ret;
    }

    for (int i = 2; i < pos + 1; i++)
    {
        ret = max(maxSerialSum(i - 1) + sequence[i], sequence[i]);
    }
    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));
    scanf("%d", &N);

    for (int i = 1; i < N + 1; i++)
    {
        scanf("%lld", sequence + i);
    }

    maxSerialSum(N);
    long long result = LONG_LONG_MIN;
    for (int i = 1; i < N + 1; i++)
    {
        result = max(result, cache[i]);
    }

    printf("%lld", result);
}
