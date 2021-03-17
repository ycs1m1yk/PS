#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int N;
vector<pair<int, int>> grid;
/*
    x, y를 뒤집기보다는 람다식 연습
*/
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
    // compare 함수에 람다식 사용
    sort(grid.begin(), grid.end(), [](auto &l, auto &r) { return l.second < r.second; });
    for (auto p : grid)
        cout << p.first << ' ' << p.second << '\n';
}