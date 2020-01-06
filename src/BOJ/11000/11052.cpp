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
const int MAX = 1001;
int p[MAX], cache[MAX];

int maxCost(int N)
{
    int &ret = cache[N];
    if (ret != -1)
        return ret;

    ret = p[N];
    for (int i = 1; i < N / 2 + 1; i++)
    {
        ret = max(ret, maxCost(N - i) + maxCost(i));
    }

    return ret;
}

int main()
{
    int N;
    memset(cache, -1, sizeof(cache));
    scanf("%d", &N);
    for (int i = 1; i < N + 1; i++)
        scanf("%d", p + i);
    printf("%d", maxCost(N));
}