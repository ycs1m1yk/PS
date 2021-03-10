#include <iostream>
#include <cstring>
#include <cmath>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
const int MAX = 100000;

int N, cache[MAX];

int sqrsum(int num)
{
    if (num < 4)
        return num;
    int &ret = cache[num];
    if (ret != -1)
        return ret;

    int sqrtNum = floor(sqrt(num));
    ret = sqrsum(num - sqrtNum * sqrtNum) + 1;
    for (int i = sqrtNum - 1; i > floor(sqrt(sqrtNum)); i--)
    {
        ret = min(ret, sqrsum(num - i * i) + 1);
    }

    return ret;
}

int main()
{
    fastio;
    memset(cache, -1, sizeof(cache));
    cin >> N;

    int a = 0;
    // 모든 제곱수를 1로 메모
    while (++a * a < MAX)
    {
        cache[a * a] = 1;
    }
    cout << sqrsum(N);
}