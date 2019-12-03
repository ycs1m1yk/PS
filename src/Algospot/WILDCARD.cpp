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
const int MAX = 101;

int C, N;
char wildCard[MAX], fileName[MAX];
int cache[MAX];

void isMatch(char c[])
{
}

int main()
{
    memset(cache, -1, sizeof(cache));
    scanf("%d", &C);

    while (C--)
    {
        scanf("%s", &wildCard);
        scanf("%d", &N);
    }
}