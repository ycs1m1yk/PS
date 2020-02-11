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

const int MAX = 102;
int y, x;
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int maze[MAX][MAX], d[MAX][MAX];
queue<pair<int, int>> Q;

void BFS(int maze[][MAX], int y, int x)
{
    d[y][x] = 1;
    Q.push({y, x});
    while (!Q.empty())
    {
        int hereY = Q.front().first;
        int hereX = Q.front().second;
        Q.pop();
        for (int i = 0; i < 4; i++)
        {
            int thereY = hereY + dy[i];
            int thereX = hereX + dx[i];
            if (thereY == y && thereX == x)
            { // 도착점일 경우
                if (d[y][x] == -1)
                    d[y][x] = d[hereY][hereX] + 1;
                else
                    d[y][x] = min(d[y][x], d[hereY][hereX] + 1);
            }
            else if (maze[thereY][thereX] && d[thereY][thereX] == -1)
            {
                // printf("y:%d, x:%d\n", thereY, thereX);
                d[thereY][thereX] = d[hereY][hereX] + 1;
                Q.push({thereY, thereX});
            }
        }
    }
}

int main()
{
    memset(d, -1, sizeof(d));
    scanf("%d %d", &y, &x);
    // 테두리그리기
    for (int i = 0; i <= y + 1; i++)
        maze[i][0] = maze[i][x + 1] = 0;
    for (int j = 0; j <= x + 1; j++)
        maze[0][j] = maze[y + 1][j] = 0;
    // 미로 입력받기
    for (int i = 1; i <= y; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            scanf("%1d", &maze[i][j]);
        }
    }
    BFS(maze, 1, 1);
    printf("%d", d[y][x]);
}