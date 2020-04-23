#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int N, K;
vector<pair<int, int>> v;

void hanoi(int n, int from, int to, int by)
{
    if (n == 1)
    {
        v.push_back(make_pair(from, to));
        return;
    }

    hanoi(n - 1, from, by, to);
    v.push_back(make_pair(from, to));
    hanoi(n - 1, by, from, to);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    hanoi(N, 1, 3, 2);

    K = v.size();
    cout << K << '\n';

    for (int i = 0; i < K; i++)
    {
        cout << v[i].first << ' ' << v[i].second << '\n';
    }
}
