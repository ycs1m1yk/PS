#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;
int N;
vector<pair<int, int>> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int start, end;
        cin >> start >> end;
        v.push_back(make_pair(end, start));
    }

    sort(v.begin(), v.end());

    int result = 0, minEnd = 0;
    int sizeOfV = v.size();
    for (int i = 0; i < sizeOfV; i++)
    {
        if (v[i].second >= minEnd)
        {
            result++;
            minEnd = v[i].first;
        }
    }

    cout << result;
}