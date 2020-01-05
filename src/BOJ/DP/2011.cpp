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
    if (!input[pos])
        return 1;
    int &ret = cache[pos];
    if (ret != -1)
        return ret;
    if (input[pos] == '0')
        return ret = 0;

    ret = d(pos + 1);

    if (input[pos] == '1' && input[pos + 1])
    {
        ret += d(pos + 2);
        ret %= DIVISOR;
    }
    if (input[pos] == '2' && input[pos + 1] && input[pos + 1] <= '6')
    {
        ret += d(pos + 2);
        ret %= DIVISOR;
    }

    return ret;
}

int main()
{
    memset(cache, -1, sizeof(cache));
    scanf("%s", input);
    printf("%d", d(0));
}