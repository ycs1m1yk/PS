#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

/*
    왜
        ios_base :: sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    쓰면 cout이 먹통이지?

    일단 scanf, printf 사용
*/

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
    for (int i = 2; i <= (int)sqrt(num); i++)
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
    int input;
    Eratos(1000000);
    while (1)
    {
        scanf("%d", &input);
        if (!input)
            break;
        for (int i = input - 3; i >= input / 2; i -= 2)
        {
            if (eratosVec[i] && eratosVec[input - i])
            {
                printf("%d = %d + %d\n", input, input - i, i);
                break;
            }
        }
    }
}