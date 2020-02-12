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

/*
    아이디어
    - 섬은 연결요소
    - 각 섬마다 넘버링
    - 두 섬을 잇는 모든 경우를 따져본다
    - 섬 i개에 (i-1)+i+...+1 = i*(i-1)/2개의 경우의 수
    
    - 섬의 가장자리끼리 연결
    - 다리의 길이 = 두 연결점간의 dy+dx-1
    - (정확한 방법은 아니지만 최소길이를 구할땐 문제없다)
    - 길이가 1인 다리가 나오면 break
*/

using namespace std;
const int MAX = 102;
const int dy[4] = {0, 0, 1, -1};
const int dx[4] = {1, -1, 0, 0};

int N, islandNum = 0;
int map[MAX][MAX], visited[MAX][MAX];
queue<pair<int, int>> Q;
// 각 섬의 가장자리 좌표를 저장해두는 벡터
// 100*100 맵에서 최대 5000개의 섬
vector<pair<int, int>> islandVec[5001];

void BFS(int map[][MAX], int y, int x)
{
    //printf("< %d번째 섬 >\n", islandNum);
    visited[y][x] = 1;
    Q.push({y, x});
    while (!Q.empty())
    {
        int hereY = Q.front().first;
        int hereX = Q.front().second;
        Q.pop();
        bool isBorder = false;
        for (int i = 0; i < 4; i++)
        {
            int thereY = hereY + dy[i];
            int thereX = hereX + dx[i];
            if (map[thereY][thereX] == 0)
                isBorder = true;
            if (map[thereY][thereX] > 0 && visited[thereY][thereX] == -1)
            {
                visited[thereY][thereX] = 1;
                Q.push({thereY, thereX});
            }
        }
        if (isBorder)
            islandVec[islandNum].push_back({hereY, hereX});
    }
}

int findPtoPDistance(int y1, int x1, int y2, int x2)
{
    int retval = abs(y2 - y1) + abs(x2 - x1) - 1;
    return retval;
}

int main()
{
    memset(visited, -1, sizeof(visited));
    scanf("%d", &N);
    for (int i = 0; i <= N + 1; i++)
    { // 테두리그리기
        map[0][i] = map[N + 1][i] = -1;
        map[i][0] = map[i][N + 1] = -1;
    }
    for (int i = 1; i <= N; i++)
    { // 0:바다, 1:육지
        for (int j = 1; j <= N; j++)
            scanf("%1d", &map[i][j]);
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (map[i][j] == 1 && visited[i][j] == -1)
            {
                islandNum++;
                BFS(map, i, j);
            }
        }
    }
    int result = INT_MAX;
    for (int i = 1; i < islandNum; i++)
    {
        if (result == 1)
            break;
        //printf("%d번째 섬:\n", i);
        for (auto pair : islandVec[i])
        {
            if (result == 1)
                break;
            int iY = pair.first;
            int iX = pair.second;
            //printf("iY:%d, iX:%d\n", iY, iX);
            for (int j = i + 1; j <= islandNum; j++)
            {
                if (result == 1)
                    break;
                //printf("\t%d번째 섬:\n", j);
                for (auto pair : islandVec[j])
                {
                    int jY = pair.first;
                    int jX = pair.second;
                    //printf("\tjY:%d, jX:%d\n", jY, jX);
                    int dist = findPtoPDistance(iY, iX, jY, jX);
                    //printf("\t current dist: %d\n", dist);
                    result = min(result, dist);
                    if (result == 1)
                        break;
                }
            }
        }
    }
    printf("%d", result);
}