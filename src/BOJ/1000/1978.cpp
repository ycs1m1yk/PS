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

bool isPrime(int num)
{
    if (num == 1)
    {
        return false;
    }
    bool ret = true;
    for (int i = num - 1; i > 1; i--)
    {
        if (num % i == 0)
        {
            ret = false;
            break;
        }
    }
    return ret;
}

int main()
{
    int N, pNumCnt = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        if (isPrime(num))
            pNumCnt++;
    }
    cout << pNumCnt;
}