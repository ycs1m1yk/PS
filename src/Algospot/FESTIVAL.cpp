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

const int MAX = 1000;
int period[MAX];
vector<double> sumArr;
vector<double> avgArr;

double festival(int N, int L)
{
    double ret;

    sumArr.clear();
    avgArr.clear();

    for (int i = L; i < N + 1; i++)
    {
        for (int j = 0; j < N - i + 1; j++)
        {
            double sum = 0;
            for (int k = 0; k < i; k++)
            {
                sum += period[j + k];
            }
            sumArr.push_back(sum);
        }
        sort(sumArr.begin(), sumArr.end());
        avgArr.push_back(sumArr[0] / i);
        sumArr.clear();
    }
    sort(avgArr.begin(), avgArr.end());

    ret = avgArr[0];
    avgArr.clear();

    return ret;
}

int main()
{
    int C, N, L;
    int val;

    memset(period, -1, sizeof(period));
    scanf("%d", &C);

    while (C--)
    {
        scanf("%d %d", &N, &L);
        for (int i = 0; i < N; i++)
        {
            if (i == N - 1)
            {
                scanf("%d", &val);
            }
            else
            {
                scanf("%d ", &val);
            }
            period[i] = val;
        }
        printf("%.10lf\n", festival(N, L));
        memset(period, -1, sizeof(period));
    }
}