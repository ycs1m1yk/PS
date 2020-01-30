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
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K;
    cin >> K;
    while (K--)
    {
        int V, E;
        vector<int> adj[20001];
        cin >> V >> E;
        for (int i = 0; i < E; i++)
        { // 인접리스트 초기화
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        bool isBipartite = true;
        int mark[20001]; // -1:방문x, 0:검은색, 1:빨간색
        memset(mark, -1, sizeof(mark));
        for (int s = 1; s <= V; s++)
        { // 1~V번 노드부터 순회(bfs)
            if (!isBipartite)
            { // 이미 NO이면 더 순회할 필요x
                break;
            }
            if (mark[s] != -1)
            {
                continue;
            }
            bool flag = false;
            queue<int> nodeQ;
            mark[s] = 1;
            nodeQ.push(s);
            while (!nodeQ.empty())
            {
                int qSize = nodeQ.size();
                for (int i = 0; i < qSize; i++)
                {
                    int curr = nodeQ.front();
                    nodeQ.pop();
                    for (int next : adj[curr])
                    {
                        if (mark[next] == -1)
                        {
                            mark[next] = flag;
                            nodeQ.push(next);
                        }
                    }
                }
                flag = !flag;
            }
            for (int u = 1; u <= V; u++)
            {
                if (!isBipartite)
                {
                    break;
                }
                for (int v : adj[u])
                {
                    if (mark[u] == mark[v])
                    {
                        isBipartite = false;
                        break;
                    }
                }
            }
        }
        cout << (isBipartite ? "YES" : "NO") << "\n";
    }
}