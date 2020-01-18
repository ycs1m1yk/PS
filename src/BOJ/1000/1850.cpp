#include <iostream>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;
const unsigned long long MAX_PRINT_LEN = 10000000;

int main()
{
    // unsigned long long range
    // : 0 to 18,446,744,073,709,551,615(2^0 ~ 2^63-1)
    unsigned long long A, B, cnt;

    cin >> A >> B;

    cnt = __gcd(A, B);

    // 정답은 천만 자리를 넘지 않는다.
    if (cnt >= MAX_PRINT_LEN)
        cnt = MAX_PRINT_LEN;
    for (int i = 0; i < cnt; i++)
        cout << '1';
}