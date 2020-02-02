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

// 사이클에 속하지못하는 학생들 골라내기
using namespace std;

int n, cicleCnt, S[100001];
bool visited[100001], cicleMember[100001];
void dfs(int curr)
{
    visited[curr] = true;
    int next = S[curr];
    if (visited[next])
    {
        if (!cicleMember[next])
        {
            for (int v = next; v != curr; v = S[v])
            {
                cicleCnt++;
            }
            cicleCnt++; // curr도 카운트
        }
    }
    else
        dfs(next);
    cicleMember[curr] = true;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    { // 테스트케이스 T번
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        { // 인접리스트 초기화
            scanf("%d", S + i);
        }

        cicleCnt = 0;
        fill(visited + 1, visited + n + 1, false);
        fill(cicleMember + 1, cicleMember + n + 1, false);
        for (int v = 1; v <= n; v++)
        {
            if (!visited[v])
            {
                dfs(v);
            }
        }
        printf("%d\n", n - cicleCnt);
    }
}