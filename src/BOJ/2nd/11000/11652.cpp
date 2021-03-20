#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
const int MAX = 100000;

int N;
long long card[MAX];

int main()
{
    fastio;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> card[i];
    }
    sort(card, card + N);
    int maxCnt = 1, cnt = 0;
    long long countingNum = card[0], currentNum;
    long long ans = card[0];
    for (int i = 0; i < N; i++)
    {
        currentNum = card[i];
        if (currentNum == countingNum)
        {
            cnt++;
            if (cnt == maxCnt)
            {
                ans = min(ans, currentNum);
            }
            if (cnt > maxCnt)
            {
                ans = currentNum;
                maxCnt = cnt;
            }
        }
        else
        {
            countingNum = currentNum;
            cnt = 1;
        }
    }
    cout << ans;
}