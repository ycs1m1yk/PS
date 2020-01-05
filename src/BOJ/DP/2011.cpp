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
    [A..Z]==[1..26]
*/

using namespace std;
const int MAX = 5001;
const int DIVISOR = 1000000;
char input[MAX];
int cache[MAX];

int d(int pos)
{
    int &ret = cache[pos];
    if (ret)
        return ret;

    if (input[pos] > '0')
        ret = d(pos - 1);
    int x = (input[pos - 1] - '0') * 10 + (input[pos] - '0');
    if (x >= 10 && x <= 26)
    {
        if (pos == 1)
            ret = 2;
        else
        {
            ret += d(pos - 2);
            ret %= DIVISOR;
        }
    }

    return ret;
}

int main()
{
    //memset(cache, -1, sizeof(cache));
    scanf("%s", input);
    if (input[0] == '0')
    {
        printf("%d", 0);
        return 0;
    }
    cache[0] = 1;
    int len = strlen(input);
    printf("%d", d(len - 1));
}