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

/*
    뭐가 틀린거지??
*/

using namespace std;
const int MAX = 1001;

int N, maxElement;
int numArr[MAX];
int dp[MAX];

int solve(int start, int N)
{
    int &ret = dp[start];
    if (N == start)
    {
        maxElement = numArr[start];
        return ret = 1;
    }
    if (ret != -1)
    {
        return ret;
    }

    ret = solve(start, N - 1);

    if (numArr[N] > maxElement)
    {
        ret += 1;
        maxElement = numArr[N];
    }

    return ret;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    scanf("%d", &N);

    for (int i = 1; i < N + 1; i++)
    {
        scanf("%d", &numArr[i]);
    }

    for (int start = 1; start < N + 1; start++)
    {
        solve(start, N);
    }
    sort(dp + 1, dp + N + 1);
    printf("%d", dp[N]);

    return 0;
}