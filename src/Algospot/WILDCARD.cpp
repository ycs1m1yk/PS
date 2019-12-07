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

/*
    나중에 풀이
    나중에 풀이
    나중에 풀이
    나중에 풀이
    나중에 풀이
*/

using namespace std;
const int MAX = 101;

int C, N;
char wildCard[MAX], fileName[50][MAX];
int cache[MAX];

int isMatch(int pos, int i)
{
    int &ret = cache[pos];
    if (ret != -1)
    {
        return ret;
    }
    if (wildCard[pos] != '*')
    {
        if ((wildCard[pos] == '?') || (wildCard[pos] == fileName[i][pos]))
        {
            ret = 1;
            isMatch(pos + 1, i);
        }
        else
            return ret = 0;
    }
    else
    {
        while ()
    }
}

int main()
{
    memset(cache, -1, sizeof(cache));
    scanf("%d", &C);

    while (C--)
    {
        getline(cin, wildCard);
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
        {
            getline(cin, fileName[i]);
        }
        printf("\n");
    }
}