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

using namespace std;

const int MAX = 10001;

int main()
{
    int N, input;
    int nArr[MAX] = {0};
    scanf("%d", &N);
    while (N--)
    {
        scanf("%d", &input);
        nArr[input]++;
    }

    for (int i = 1; i < MAX; i++)
    {
        while (nArr[i] > 0)
        {
            printf("%d\n", i);
            nArr[i]--;
        }
    }
}