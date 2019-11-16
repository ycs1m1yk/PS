#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <deque>
#include <queue>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

/*
오답
*/

int stairNum[101][10] = {
    0,
};

int stair(int input, int val)
{
    if (input == 1)
    {
        if (val == 0)
        {
            return 0;
        }
        return 1;
    }
    if (stairNum[input][val] != 0)
    {
        return stairNum[input][val];
    }

    if (val - 1 != -1)
    {
        stairNum[input][val] += stair(input - 1, val - 1);
    }
    if (val + 1 != 10)
    {
        stairNum[input][val] += stair(input - 1, val + 1);
    }
    return stairNum[input][val];
}

int main()
{
    int N, result = 0;

    scanf("%d", &N);
    for (int i = 0; i < 10; i++)
    {
        result += stair(N, i);
    }
    printf("%d", result % 1000000000);
}