#include <iostream>
#include <stdio.h>
#include <math.h>
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
const int MAX = 1001;

int N, max1;
int sequence[MAX];
int cache[MAX];

int dp(int size)
{
    int &ret = cache[size];
    if (size == 1)
    {
        return ret = 1;
    }
    if (cache[size] != -1)
    {
        return ret;
    }

    dp(size - 1);

    for (int i = 1; i < size; i++)
    {
        if (sequence[size] < sequence[i])
        {
            if (cache[i] > max1)
            {
                max1 = cache[i];
            }
        }
    }
    ret = max1 + 1;
    max1 = 0;

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));
    scanf("%d", &N);

    for (int i = 1; i < N + 1; i++)
    {
        scanf("%d", &sequence[i]);
    }

    dp(N);

    int ret = 0;
    for (int i = 1; i < N + 1; i++)
    {
        ret = max(ret, cache[i]);
    }

    printf("%d", ret);
    return 0;
}