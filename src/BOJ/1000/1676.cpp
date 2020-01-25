#include <iostream>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <ctime>

/*
    1! = 1
    2! = 2
    3! = 6
    4! = 24   
    5! = 120  
    6! = 720  
    7! = 5040 
    8! = 40320
    9! = 362880   
    10! = 3628800 
    11! = 39916800
    12! = 479001600
    13! = 6227020800
    14! = 87178291200
    15! = 1307674368000
    .
    .
    .
*/
using namespace std;

const int MOD = 1000000000; // 10억

int main()
{
    int N, firstNonZero, cntZero = 0;
    uint64_t result = 1;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        result *= i;
        result %= MOD;
        // cout << "i = " << i << ": " << result << "\n";
        while (result % 10 == 0)
        {
            cntZero++;
            result /= 10;
        }
    }
    cout << cntZero;
}