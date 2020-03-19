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
const int MAX = 500000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, input;
    int card[MAX];

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> card[i];
    sort(card, card + N);

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int lo = 0, hi = N;
        cin >> input;
        while (lo + 1 < hi)
        {
            int mid = (lo + hi) / 2;
            if (input >= card[mid])
                lo = mid;
            else
                hi = mid;
        }
        cout << ((input == card[lo]) ? 1 : 0) << " ";
    }
}