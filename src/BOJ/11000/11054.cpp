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

int N;
int sequence[MAX];
int cache[MAX][2];
/*
    cache[pivot][0]: pivot포함 증가수열길이
    cache[pivot][1]: pivot포함 감소수열길이
*/

int longestISS(int pivot)
{
    int &ret = cache[pivot][0];
    if (pivot == 1)
    {
        return ret = 1;
    }
    if (ret != -1)
    {
        return ret;
    }

    ret = 0;

    for (int i = pivot - 1; i > 0; i--)
    {
        if (sequence[pivot] > sequence[i])
        {
            ret = max(ret, longestISS(i));
        }
    }
    return ++ret;
}
int longestDSS(int pivot)
{
    int &ret = cache[pivot][1];
    if (pivot == N)
    {
        return ret = 1;
    }
    if (ret != -1)
    {
        return ret;
    }

    ret = 0;

    for (int i = pivot + 1; i < N + 1; i++)
    {
        if (sequence[pivot] > sequence[i])
        {
            ret = max(ret, longestDSS(i));
        }
    }
    return ++ret;
}

int main()
{
    int result = 0;
    memset(cache, -1, sizeof(cache));
    scanf("%d", &N);

    for (int i = 1; i < N + 1; i++)
    {
        scanf("%d", &sequence[i]);
    }

    for (int i = 1; i < N + 1; i++)
    {
        result = max(result, longestISS(i) + longestDSS(i) - 1);
    }

    printf("%d", result);
}