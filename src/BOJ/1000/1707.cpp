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
#include <set>

using namespace std;

const int MAX_SIZE = 20001;
queue<int> nodeQ;

int main()
{
    int K;
    cin >> K;
    for (int k = 0; k < K; k++) // K번 테스트
    {
        int V, E;
        cin >> V >> E;
        if (V == 1)
        {
            cout << "YES"
                 << "\n";
            continue;
        }
        int d[MAX_SIZE], visited[MAX_SIZE] = {0};
        int adj[MAX_SIZE][MAX_SIZE] = {0};
        vector<set<int>> distanceSetVec; // 시작노드로부터의 거리 set
        for (int i = 0; i < E; i++)      // 인접행렬 초기화
        {
            int v, u;
            cin >> v >> u;
            adj[v][u] = 1;
            adj[u][v] = 1;
        }
        bool isBipartite = true;
        // #################### BFS시작
        for (int s = 1; s <= V; s++) // 시작노드 1~V번
        {
            if (!isBipartite) // 이미 Bipartite가 아니면 더 순회안해봐도됨.
            {
                break;
            }
            memset(d, -1, sizeof(d));
            memset(visited, 0, sizeof(visited));

            d[s] = 0; // s부터 순회
            visited[s] = 1;
            distanceSetVec.push_back({s});
            nodeQ.push(s);
            while (!nodeQ.empty())
            {
                int curNode = nodeQ.front();
                nodeQ.pop();
                for (int i = 1; i <= V; i++)
                {
                    if (adj[curNode][i])
                    {
                        if (!visited[i])
                        {
                            visited[i] = 1;
                            d[i] = d[curNode] + 1;
                            nodeQ.push(i);
                            if (d[i] + 1 > distanceSetVec.size())
                            {
                                distanceSetVec.push_back({i});
                            }
                            else
                            {
                                distanceSetVec[d[i]].insert(i);
                            }
                        }
                    }
                }
            }
            // #################### BFS 종료
            for (auto set : distanceSetVec)
            {
                if (!isBipartite)
                {
                    break;
                }
                int firstElement = *(set.begin());
                for (auto e : set)
                {
                    if (e == firstElement)
                    {
                        continue;
                    }
                    if (adj[firstElement][e])
                    {
                        isBipartite = false;
                        break;
                    }
                }
            }
        }

        if (isBipartite)
        {
            cout << "YES"
                 << "\n";
        }
        else
        {
            cout << "NO"
                 << "\n";
        }
    }
}
