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

vector<int> primeNums;
void Eratos(int num)
{
    if (num <= 1)
    {
        return;
    }
    for (int i = 0; i <= num; i++)
    {
        primeNums.push_back(true);
    }
    primeNums[0] = false;
    primeNums[1] = false;
    for (int i = 2; i <= (int)sqrt(num); i++)
    {
        if (primeNums[i])
        {
            for (int j = i * i; j <= num; j += i)
            {
                primeNums[j] = false;
            }
        }
    }
}

int main()
{
    int N;
    cin >> N;
    Eratos(N);
    for (int i = 2; i <= primeNums.size(); i++)
    {
        if (primeNums[i])
        {
            while (N % i == 0)
            {
                N /= i;
                cout << i << "\n";
                if (N == 1)
                {
                    break;
                }
            }
        }
    }
}