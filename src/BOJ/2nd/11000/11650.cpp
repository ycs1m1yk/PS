#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int N;
vector<pair<int, int>> grid;
int main()
{
    fastio;
    cin >> N;
    int x, y;
    while (N--)
    {
        cin >> x >> y;
        grid.push_back(make_pair(x, y));
    }
    sort(grid.begin(), grid.end());
    for (auto p : grid)
        cout << p.first << ' ' << p.second << '\n';
}