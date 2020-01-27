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
const int MAX = 1001;

int visited[MAX] = {0};
int d[MAX], pi[MAX];
int adj[MAX][MAX] = {0};

void dfs(int G[][MAX], int V, int N)
{
    visited[V] = 1;
    cout << V << " ";
    for (int U = 1; U <= N; U++)
    {
        if (adj[V][U])
        {
            if (!visited[U])
                dfs(G, U, N);
        }
    }
    return;
}
void bfs(int G[][MAX], int S, int N)
{
    queue<int> bfsQ;
    d[S] = 0;
    bfsQ.push(S);
    while (!bfsQ.empty())
    {
        int V = bfsQ.front();
        cout << V << " ";
        bfsQ.pop();
        for (int U = 1; U <= N; U++)
        {
            if (adj[V][U])
            {
                if (d[U] == -1)
                {
                    d[U] = d[V] + 1;
                    pi[U] = V;
                    bfsQ.push(U);
                }
            }
        }
    }
    return;
}

int main()
{
    int N, M, V;
    memset(d, -1, sizeof(d));
    memset(pi, -1, sizeof(pi));
    cin >> N >> M >> V;
    for (int i = 0; i < M; i++)
    {
        int vertex, edge;
        cin >> vertex >> edge;
        adj[vertex][edge]++;
        adj[edge][vertex]++;
    }
    dfs(adj, V, N);
    cout << "\n";
    bfs(adj, V, N);
}