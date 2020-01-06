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
    int n;
    while ((n < 1) || (n > 9))
    {

        scanf("%d", &n);
    }
    for (int i = 1; i < 10; i++)
    {
        printf("%d * %d = %d\n", n, i, n * i);
    }

    return 0;
}