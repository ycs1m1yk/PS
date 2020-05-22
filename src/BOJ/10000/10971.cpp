#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
int N, W[11][11];
vector<int> v;

int main()
{
    memset(W, -1, sizeof(W));

    cin >> N;

    v.push_back(0);
    for (int i = 1; i <= N; i++)
    {
        v.push_back(i);
        for (int j = 1; j <= N; j++)
        {
            cin >> W[i][j];
        }
    }

    int result = 1000000 * 11;
    do
    {
        bool flag = false;
        int sum = 0;
        if (W[v[N]][v[1]] == 0) // 갈 수 없는 case
            continue;
        else
        {
            sum += W[v[N]][v[1]];             // 마지막경로
            for (int pos = 1; pos < N; pos++) // 중간경로들 permutation
            {
                int tmp = W[v[pos]][v[pos + 1]];
                if (tmp == 0)
                { // 갈 수 없는 case
                    flag = true;
                    break;
                }
                else
                    sum += tmp;
            }
        }
        if (flag)
            continue;
        result = min(result, sum);
    } while (next_permutation(v.begin() + 1, v.end()));

    cout << result;
}