#include <iostream>
#include <cstdio>
#include <cmath>
#include <limits>
#include <cstring>
#include <cstdlib>
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
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, lo = 0, hi = -1; // 높이 최솟값==0
    int tree[1000000];
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> tree[i];
        hi = max(hi, tree[i] + 1);
    }

    if (hi <= 1)
    { // hi가 1인경우 예외처리
        cout << 0;
        return 0;
    }

    while (lo + 1 < hi)
    {
        int mid = (lo + hi) / 2;
        long long total = 0;
        for (int i = 0; i < N; i++)
        {
            if (total >= M)
                break;
            if (tree[i] > mid)
                total += tree[i] - mid;
        }
        if (total >= M)
            lo = mid;
        else
            hi = mid;
    }
    cout << lo << "\n";
}