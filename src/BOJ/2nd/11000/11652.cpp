#include <iostream>
#include <algorithm>
#include <map>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef map<long long, int> M;

int N;
M cards;

int main()
{
    fastio;
    cin >> N;
    long long cardNum;
    for (int i = 0; i < N; i++)
    {
        cin >> cardNum;
        M::iterator iter = cards.find(cardNum);
        if (iter == cards.end()) // cardNum을 못 찾았을때
            cards[cardNum] = 1;
        else
            iter->second++;
    }

    int maxCnt = 0;
    int ans;
    for (auto pair : cards)
    {
        if (pair.second > maxCnt || pair.second == maxCnt && pair.first < ans)
        {
            ans = pair.first;
            maxCnt = pair.second;
        }
    }
    cout << ans;
}