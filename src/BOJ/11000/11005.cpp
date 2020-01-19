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
    string N;
    int B, leadingTerm, ret = 0;
    cin >> N >> B;
    leadingTerm = N.size() - 1;
    for (auto coef = N.begin(); coef != N.end(); coef++)
    {
        int iCoef;
        if (*coef >= 'A')
        {
            iCoef = *coef - 'A' + 10;
        }
        else
        {
            iCoef = *coef - '0';
        }
        ret += iCoef * pow(B, leadingTerm);
        leadingTerm--;
    }
    cout << ret;
}