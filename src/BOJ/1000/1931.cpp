#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;
int N, result = 0;
vector<pair<int, int>> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    int minEnd = INT_MAX;
    for (int i = 0; i < N; i++)
    {
        int start, end;
        cin >> start >> end;
        minEnd = min(minEnd, end);
        v.push_back(make_pair(start, end));
    }

    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    });

    int sizeOfV = v.size();
    for (int i = 0; i < sizeOfV; i++)
    {
        if (v[i].first < minEnd)
            continue;
        else
        {
            result++;
            minEnd = v[i].second;
        }
    }

    cout << result;
}