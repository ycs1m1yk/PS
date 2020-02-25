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
#include <tuple>

using namespace std;
const int MAX = 1002;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
int M, N;
int tomatoBox[MAX][MAX];
int d[MAX][MAX];

int main()
{
    queue<pair<int, int>> Q;
    memset(d, -1, sizeof(d));
    scanf("%d %d", &M, &N);
    // 테두리(-1)그리기
    for (int i = 0; i <= M + 1; i++)
    {
        tomatoBox[0][i] = tomatoBox[N + 1][i] = -1;
    }
    for (int j = 0; j <= N + 1; j++)
    {
        tomatoBox[j][0] = tomatoBox[j][M + 1] = -1;
    }

    // 토마토상자 상태입력
    for (int row = 1; row <= N; row++)
    {
        for (int col = 1; col <= M; col++)
        {
            scanf("%d", &tomatoBox[row][col]);
            if (tomatoBox[row][col] == 1)
            {
                Q.push({row, col});
                d[row][col] = 0;
            }
        }
    }
    while (!Q.empty())
    {
        int currRow = Q.front().first;
        int currCol = Q.front().second;
        Q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nRow = currRow + dx[i];
            int nCol = currCol + dy[i];
            if (tomatoBox[nRow][nCol] == 0 && d[nRow][nCol] == -1)
            {
                d[nRow][nCol] = d[currRow][currCol] + 1;
                Q.push({nRow, nCol});
            }
        }
    }
    int result = 0;
    for (int i = 1; i <= N; i++)
    {
        if (result == -1)
            break;
        for (int j = 1; j <= M; j++)
        {
            if (tomatoBox[i][j] == 0 && d[i][j] == -1)
            {
                result = -1;
                break;
            }
            result = max(result, d[i][j]);
        }
    }
    printf("%d", result);
}