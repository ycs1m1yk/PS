#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>

using namespace std;
int main()
{
    int N, M;
    vector<set<int>> connectedSetVec;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        connectedSetVec.push_back({i});
    }
    for (int i = 0; i < M; i++)
    {
        int u, v, uPos, vPos;
        set<int> uSet, vSet;
        bool uFound = false, vFound = false;
        cin >> u >> v;
        for (int i = 0; i < connectedSetVec.size(); i++)
        {
            if (uFound && vFound)
            {
                break;
            }

            if (connectedSetVec[i].find(u) != connectedSetVec[i].end())
            {
                uPos = i;
                uSet = connectedSetVec[i];
                uFound = true;
            }
            if (connectedSetVec[i].find(v) != connectedSetVec[i].end())
            {
                vPos = i;
                vSet = connectedSetVec[i];
                vFound = true;
            }
        }
        if (uSet != vSet)
        {
            for (auto e : vSet)
            {
                connectedSetVec[uPos].insert(e);
            }
            connectedSetVec[vPos] = {};
            cout << "connectedSetVec: ";
            // for (auto set : connectedSetVec)
            // {
            //     cout << "{";
            //     for (auto e : set)
            //     {
            //         cout << e << ", ";
            //     }
            //     cout << "} ";
            // }
            // cout << "\n";
        }
    }
    int cnt = 0;
    set<int> nullSet = {};
    for (auto set : connectedSetVec)
    {
        if (set != nullSet)
        {
            cnt++;
        }
    }
    cout << cnt;
}