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
    시간초과...
*/

using namespace std;
const int MAX = 100001;
const int ROOT_MAX = 317; // sqrt(100000) == 316.xx...

int cache[MAX], cnt[ROOT_MAX];

int solve(int N)
{
    int &ret = cache[N];
    int rootN = (int)floor(sqrt(N));
    if (ret != -1)
    {
        return ret;
    }
    ret = MAX;
    for (int i = rootN; i > 0; i--)
    {
        ret = min(ret, solve(N - i * i) + 1);
    }
    return ret;
}

int main()
{
    int N;
    memset(cache, -1, sizeof(cache));
    for (int i = 1; i < ROOT_MAX; i++)
    {
        cache[i * i] = 1;
        cache[i * i + 1] = 2;
    }
    scanf("%d", &N);
    printf("%d", solve(N));
}
