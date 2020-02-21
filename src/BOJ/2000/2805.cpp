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

    int N, M, lo = 1, hi = -1;
    int tree[1000000];
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> tree[i];
        hi = max(hi, tree[i] + 1);
    }

    while (lo + 1 < hi)
    {
        int mid = (lo + hi) / 2, total = 0;
        // cout<<mid<<"\n";
        for (int i = 0; i < N; i++)
        {
            if (total >= M)
                break;
            if (tree[i] > mid)
                total += tree[i] - mid;
        }
        // cout<<"total: "<<total<<"\n";
        if (total >= M)
            lo = mid;
        else
            hi = mid;

        // cout << lo << " " << hi << "\n\n";
    }
    cout << lo << "\n";
}