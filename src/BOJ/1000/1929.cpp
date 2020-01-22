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
#include <tuple>

using namespace std;

vector<bool> eratosVec;

void Eratos(int num)
{
    if (num <= 1)
    {
        return;
    }
    for (int i = 0; i <= num; i++)
    {
        eratosVec.push_back(true);
    }
    eratosVec[1] = false;
    for (int i = 2; i <= num; i++)
    {
        if (eratosVec[i])
        {
            for (int j = i * i; j <= num; j += i)
            {
                eratosVec[j] = false;
            }
        }
    }
}

int main()
{
    int M, N = 0;
    cin >> M >> N;
    if (M == N == 1)
    {
        return 0;
    }
    Eratos(N);
    for (int i = M; i <= N; i++)
    {
        if (eratosVec[i])
            cout << i << "\n";
    }
}