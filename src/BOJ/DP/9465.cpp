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
    case  | row | N-1 |  N
----------|-----|-----|-----
      0   |  0  |  0  |  ?
          |  1  |  0  |  ?
----------|-----|-----|-----
      1   |  0  |  1  |  0
          |  1  |  0  |  ?
----------|     |-----|-----
      2   |  0  |  0  |  ?
          |  1  |  1  |  0
----------|-----|-----|-----
          
*/

using namespace std;

const int MAX = 100001;
int sticker[2][MAX];
int dp[MAX][3] = {
    0,
};

int main()
{
    int T, n, ret;

    memset(sticker, -1, sizeof(sticker));
    scanf("%d", &T);

    while (T--)
    {
        scanf("%d", &n);

        for (int row = 0; row < 2; row++)
        {
            for (int col = 1; col < n + 1; col++)
            {
                scanf("%d", &sticker[row][col]);
            }
        }

        for (int i = 1; i < n + 1; i++)
        {
            dp[i][0] = max(max(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]);
            dp[i][1] = sticker[0][i] + max(dp[i - 1][0], dp[i - 1][2]);
            dp[i][2] = sticker[1][i] + max(dp[i - 1][0], dp[i - 1][1]);
        }

        ret = max(max(dp[n][0], dp[n][1]), dp[n][2]);

        printf("%d\n", ret);
        memset(sticker, -1, sizeof(sticker));
    }
}