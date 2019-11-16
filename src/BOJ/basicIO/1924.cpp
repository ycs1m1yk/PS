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
    char cDay[7][4] =
        {"SUN",
         "MON",
         "TUE",
         "WED",
         "THU",
         "FRI",
         "SAT"};
    int iMonthArr[12] =
        {31,
         28,
         31,
         30,
         31,
         30,
         31,
         31,
         30,
         31,
         30,
         31};

    int iMonth,
        iDay;
    int sum = 0;

    scanf("%d %d", &iMonth, &iDay);
    for (int i = 0; i < iMonth - 1; i++)
    {
        sum += iMonthArr[i];
    }
    sum += iDay;
    printf("%s", cDay[sum % 7]);

    return 0;
}