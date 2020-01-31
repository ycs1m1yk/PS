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
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        int mark[N + 1]; // -1: 방문x, 방문할때마다 +1
        vector<int> adj[N + 1];
        memset(mark, -1, sizeof(mark));
        for (int u = 1; u <= N; u++)
        {
            int v;
            cin >> v;
            mark[v]++;
            adj[u].push_back(v);
        }
        for (int s = 1; s <= N; s++)
        {
            if (adj[s].empty())
            {
                continue;
            }
            int back = adj[s].back();
            if (back == s)
            {
                continue;
            }
            while (!adj[back].empty())
            {
                adj[s].push_back(adj[back].back());
                int newBack = adj[back].back();
                adj[back].clear();
                back = newBack;
                if (back == s)
                {
                    break;
                }
            }
        }

        int cnt = 0;
        for (int i = 1; i <= N; i++)
        {
            if (adj[i].empty())
                continue;
            bool isCicle = true;
            if (adj[i].back() == i)
            {
                for (auto e : adj[i])
                {
                    if (mark[e] != 0)
                    {
                        isCicle = false;
                        break;
                    }
                }
            }
            else
            {
                isCicle = false;
            }
            if (isCicle)
                cnt++;
        }
        cout << cnt << "\n";
    }
}