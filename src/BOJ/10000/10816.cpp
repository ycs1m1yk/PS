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
    if (N == 1)
    {
        for (int i = 0; i < M; i++)
        {
            cin >> input;
            cout << ((input == card[0]) ? 1 : 0) << " ";
        }
    }
    else
    {
        for (int i = 0; i < M; i++)
        {
            int lo = 0, hi = N, cnt = 0;
            cin >> input;
            // input을 입력할때마다 이분탐색 실행
            while (lo + 1 < hi)
            {
                int mid = (lo + hi) / 2;
                if (input > card[mid])
                    lo = mid;
                else if (input == card[mid])
                {
                    int begin;
                    if (card[0] == input)
                        begin = 0;
                    else
                    {
                        for (int i = mid; i >= 0; i--)
                        {
                            if (card[i] != input)
                            {
                                begin = i + 1;
                                break;
                            }
                        }
                    }
                    for (int i = begin; i < N; i++)
                    {
                        if (card[i] == input)
                            cnt++;
                        else
                            break;
                    }

                    break;
                }
                else
                    hi = mid;
            }
            cout << cnt << " ";
        }
    }
}