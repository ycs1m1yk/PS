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

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

using namespace std;
int main()
{

    int n, min, max;
    int input;
    vector<int> iVec(0);

    scanf("%d", &n);

    while (n--)
    {
        if (n == 0)
        {
            scanf("%d", &input);
        }
        else
        {
            scanf("%d ", &input);
        }
        iVec.push_back(input);
    }

    sort(iVec.begin(), iVec.end());
    cout << iVec[0] << " ";
    cout << iVec[iVec.size() - 1];

    return 0;
}