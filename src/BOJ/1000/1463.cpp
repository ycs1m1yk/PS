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

int minOperation[1000000] = {
    0,
};

int getMinOperation(int input)
{

    if (input == 1)
    {
        return 0;
    }

    if (minOperation[input] != 0)
    {
        return minOperation[input];
    }

    int result = getMinOperation(input - 1) + 1;

    if (input % 3 == 0)
    {
        result = min(result, getMinOperation(input / 3) + 1);
    }
    else if (input % 2 == 0)
    {
        result = min(result, getMinOperation(input / 2) + 1);
    }
    minOperation[input] = result;
    return result;
}

int main()
{
    int input = 0;

    while ((input < 1) || (input > 1000000))
    {
        scanf("%d", &input);
    }

    printf("%d", getMinOperation(input));
}