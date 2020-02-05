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

// 연결요소개수 구하기
// 특이사항은 대각선으로도 연결됨
/*
    왜틀림? 왜틀림? 왜틀림? 왜틀림? 왜틀림?
    왜틀림? 왜틀림? 왜틀림? 왜틀림? 왜틀림?
    왜틀림? 왜틀림? 왜틀림? 왜틀림? 왜틀림?
    왜틀림? 왜틀림? 왜틀림? 왜틀림? 왜틀림?
    왜틀림? 왜틀림? 왜틀림? 왜틀림? 왜틀림?
    왜틀림? 왜틀림? 왜틀림? 왜틀림? 왜틀림?
    왜틀림? 왜틀림? 왜틀림? 왜틀림? 왜틀림?
    왜틀림? 왜틀림? 왜틀림? 왜틀림? 왜틀림?
*/
using namespace std;
int w, h, input;
bool map[50][50], visited[50 * 50];
vector<int> adj[50 * 50];

void dfs(int curr)
{
    visited[curr] = 1;
    for (int i = 0; i < adj[curr].size(); i++)
    {
        if (!visited[adj[curr][i]])
        {
            dfs(adj[curr][i]);
        }
    }
}

int main()
{
    while (1)
    {
        scanf("%d %d", &w, &h);
        if (w == 0 && h == 0) // 입력이 0 0일때 종료.
            break;

        for (auto vec : adj)
        {
            vec.clear();
        }
        memset(map, 0, sizeof(map));
        memset(visited, 0, sizeof(visited));

        for (int row = 0; row < h; row++)
        {
            for (int col = 0; col < w; col++)
            {
                scanf("%1d", &input);
                map[row][col] = input;

                if (input && col && map[row][col - 1])
                { // 왼쪽
                    int piCurr = row * w + col - 1;
                    int curr = piCurr + 1;
                    adj[piCurr].push_back(curr);
                    adj[curr].push_back(piCurr);
                }
                if (input && row && col && map[row - 1][col - 1])
                { // 왼쪽위
                    int piCurr = (row - 1) * w + col - 1;
                    int curr = piCurr + w + 1;
                    adj[piCurr].push_back(curr);
                    adj[curr].push_back(piCurr);
                }
                if (input && row && map[row - 1][col])
                { // 위
                    int piCurr = (row - 1) * w + col;
                    int curr = piCurr + w;
                    adj[piCurr].push_back(curr);
                    adj[curr].push_back(piCurr);
                }
                if (input && row && (col < w - 1) && map[row - 1][col + 1])
                { // 오른쪽위
                    int piCurr = (row - 1) * w + col + 1;
                    int curr = piCurr + w - 1;
                    adj[piCurr].push_back(curr);
                    adj[curr].push_back(piCurr);
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < w * h; i++)
        {
            if (!visited[i] && map[i / w][i % w])
            {
                cnt++;
                dfs(i);
            }
        }
        printf("%d\n", cnt);
    }
}