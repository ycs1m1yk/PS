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
int main()
{
    int n, sum = 0;

    while ((n < 1) || (n > 10000))
    {
        scanf("%d", &n);
    }

    for (int i = 1; i < n + 1; i++)
    {
        sum += i;
    }

    printf("%d", sum);

    return 0;
}