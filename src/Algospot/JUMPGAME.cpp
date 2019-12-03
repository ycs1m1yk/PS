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
const int MAX = 101;

int C, N;
int matrix[MAX][MAX], cache[MAX][MAX];

int judgeIsReachable(int y, int x)
{
    if ((x >= N) || (y >= N))
    {
        return 0;
    }
    int &ret = cache[y][x];
    if ((x == N - 1) && (y == N - 1))
    {
        return 1;
    }
    if (ret != -1)
    {
        return ret;
    }
    int posVal = matrix[y][x];
    return ret = (judgeIsReachable(y + posVal, x) || judgeIsReachable(y, x + posVal));
}

int main()
{
    memset(cache, -1, sizeof(cache));
    scanf("%d", &C);

    while (C--)
    {
        scanf("%d", &N);
        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < N; x++)
            {
                scanf("%d", &matrix[y][x]);
            }
        }
        judgeIsReachable(0, 0) ? printf("YES\n") : printf("NO\n");
        fill_n(&matrix[0][0], (MAX - 1) * MAX, 0);
        memset(cache, -1, sizeof(cache));
    }
}