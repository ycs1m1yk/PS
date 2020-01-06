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
const int MAX = 10001;
const int CASE = 6;

int wine[MAX];
int dp[MAX][CASE];
/*
    Case|N-3 N-2 N-1  N
    0     ?   0   0   1
    1     ?   0   1   1
    2     ?   1   0   1
    3     ?   1   1   0
    4     ?   0   1   0
    5     ?   1   0   0
*/
int main()
{
    int N, ret;

    memset(wine, -1, sizeof(wine));
    scanf("%d", &N);

    for (int i = 1; i < N + 1; i++)
    {
        scanf("%d", &wine[i]);
    }

    dp[1][0] = wine[1];
    dp[1][1] = wine[1];
    dp[1][2] = wine[1];
    dp[1][3] = 0;
    dp[1][4] = 0;
    dp[1][5] = 0;

    for (int i = 2; i < N + 1; i++)
    {
        dp[i][0] = wine[i] + dp[i - 1][5];
        dp[i][1] = wine[i] + max(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = wine[i] + max(dp[i - 1][3], dp[i - 1][4]);
        dp[i][3] = dp[i - 1][1];
        dp[i][4] = max(dp[i - 1][0], dp[i - 1][2]);
        dp[i][5] = max(dp[i - 1][3], dp[i - 1][4]);
    }

    ret = max(max(max(max(max(dp[N][0], dp[N][1]), dp[N][2]), dp[N][3]), dp[N][4]), dp[N][5]);
    printf("%d", ret);

    return 0;
}
