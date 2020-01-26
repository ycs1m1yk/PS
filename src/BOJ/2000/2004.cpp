#include <iostream>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <deque>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
#include <tuple>

using namespace std;
/* 
    #1 nCr = n!/(r!*(n-r)!)
이하 출처: (https://jaimemin.tistory.com/908)
    #2 숫자의 끝자리 0의 개수: 소인수분해했을때 min(2의개수, 5의개수)
    #3 알고리즘을 일반화시키기 위해 구하는 숫자를 i라고 하겠습니다.

        1. i의 개수에 N/i만큼 더한다.

        2. i^2의 배수 같은 경우 i로 나눈다고 해도 또 i가 남아있기 때문에 i의 개수에 N/(i^2)만큼 더합니다.

        3. i^3의 배수 같은 경우 i^2로 나눈다고 해도 또 i가 남아있기 때문에 i의 개수에 N/(i^3)만큼 더합니다.

        4. 이후 같은 과정 반복
*/

pair<long long, long long> countZeros(long long N)
{
    long long two = 0, five = 0;
    // for문쓸때 반복자를 기계적으로 int i로 쓰지않기!!
    // int로해서 런타임에러 발생함
    for (long long i = 2; i <= N; i *= 2)
    {
        two += N / i;
    }
    for (long long i = 5; i <= N; i *= 5)
    {
        five += N / i;
    }
    return make_pair(two, five);
}

int main()
{
    long long N, M;
    cin >> N >> M;
    pair<long long, long long> nPair = countZeros(N);
    pair<long long, long long> mPair = countZeros(M);
    pair<long long, long long> nMinusmPair = countZeros(N - M);
    cout << min(nPair.first - mPair.first - nMinusmPair.first, nPair.second - mPair.second - nMinusmPair.second) << "\n";
}