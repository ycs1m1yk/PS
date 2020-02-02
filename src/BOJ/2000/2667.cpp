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

// 연결요소(단지)의 수와 각 연결요소의 크기를 구한다.
using namespace std;

int N;
bool map[25][25], visited[25 * 25];
vector<int> adj[25 * 25];
vector<int> sizeOfComplex; // 단지의 크기 벡터

void dfs(int curr)
{
    visited[curr] = 1;
    for (int i = 0; i < adj[curr].size(); i++)
    {
        if (!visited[adj[curr][i]])
        {
            sizeOfComplex.back()++;
            dfs(adj[curr][i]);
        }
    }
}

int main()
{
    scanf("%d", &N);
    memset(map, 0, sizeof(map));
    memset(visited, 0, sizeof(visited));
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            int input;
            scanf("%1d", &input);
            map[row][col] = input;
            if (input && col && map[row][col - 1])
            {
                int piCurr = row * N + col - 1;
                int curr = piCurr + 1;
                adj[piCurr].push_back(curr);
                adj[curr].push_back(piCurr);
            }
            if (input && row && map[row - 1][col])
            {
                int piCurr = (row - 1) * N + col;
                int curr = piCurr + N;
                adj[piCurr].push_back(curr);
                adj[curr].push_back(piCurr);
            }
        }
    }
    // int index=0;
    // for (auto list : adj)
    // {
    //     if(!list.size()){
    //         index++;
    //         continue;
    //     }
    //     printf("%d", index);
    //     index++;
    //     for (auto e : list)
    //     {
    //         printf("->%d", e);
    //     }
    //     printf("\n");
    // }
    for (int i = 0; i < N * N; i++)
    {
        if (!visited[i] && map[i / N][i % N])
        {
            sizeOfComplex.push_back(1);
            dfs(i);
        }
    }
    sort(sizeOfComplex.begin(), sizeOfComplex.end());
    printf("%d\n", sizeOfComplex.size());
    for (int e : sizeOfComplex)
    {
        printf("%d\n", e);
    }
}