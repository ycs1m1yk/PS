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

int main()
{
    int N, num;
    vector<int> incOrder;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &num);
        incOrder.push_back(num);
    }
    sort(incOrder.begin(), incOrder.end());
    for (int i = 0; i < N; i++)
    {
        if (incOrder[i] == incOrder[i + 1])
        {
            continue;
        }
        printf("%d\n", incOrder[i]);
    }
}