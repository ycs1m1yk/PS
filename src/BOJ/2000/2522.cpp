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

    scanf("%d", &n);

    for (int i = -n + 1; i < n; i++)
    {
        for (int j = 0; j < abs(i); j++)
        {
            printf(" ");
        }
        for (int j = 0; j < n - abs(i); j++)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}