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

bool judgeIsReachable(int x, int y)
{
    int &posVal = matrix[x][y];
    if ((x == N) && (y == N))
    {
        return true;
    }
    if ((x > N) || (y > N))
    {
        return false;
    }
    return judgeIsReachable(x + posVal, y) || judgeIsReachable(x, y + posVal);
}

int main()
{
    scanf("%d", &C);

    while (C--)
    {
        scanf("%d", &N);
        for (int i = 1; i < N + 1; i++)
        {
            for (int j = 1; j < N + 1; j++)
            {
                scanf("%d", &matrix[i][j]);
            }
        }
        judgeIsReachable(1, 1) ? printf("YES\n") : printf("NO\n");
    }
}