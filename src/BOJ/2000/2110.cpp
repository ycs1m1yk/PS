#include <iostream>
#include <cstdio>
#include <cmath>
#include <limits>
#include <cstring>
#include <cstdlib>
#include <string>

#include <deque>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
#include <tuple>

using namespace std;
int N, C, mid;
long long lo = 1, hi = -1;
int house[200000];

bool isValid(int curr, int remain)
{
    if (remain == 0)
        return true;
    for (int i = curr + 1; i < N; i++)
    {
        if (house[i] - house[curr] >= mid)
        {
            return isValid(i, remain - 1);
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> C;
    for (int i = 0; i < N; i++)
    {
        cin >> house[i];
    }
    sort(house, house + N);
    hi = house[N - 1] + 1;
    while (lo + 1 < hi)
    {
        mid = (lo + hi) / 2;
        if (isValid(0, C - 1))
            lo = mid;
        else
            hi = mid;
    }
    cout << lo << "\n";
}