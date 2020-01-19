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
    8924 = 8*10^3+9*10^2+2*10^1+4*10^0
*/
int main()
{
    int N, B, leadingTerm = -1;
    cin >> N >> B;
    int tmp = N;
    while (tmp >= 1)
    {
        tmp /= B;
        leadingTerm++;
    }
    for (int i = leadingTerm; i >= 0; i--)
    {
        int coef = N / pow(B, i);
        N -= coef * pow(B, i);
        if (coef >= 10)
        {
            cout << (char)('A' - 10 + coef);
        }
        else
        {
            cout << coef;
        }
    }
}