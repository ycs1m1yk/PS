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

const int MAX = 10001;
int wine[MAX];

int getMaxVolume(int N)
{
    // if(N==1){
    //     return wine[0];
    // }

    /*
    getMaxVolume(N-1)에서 N번쨰 wine 선택가능 case {(N-1) or (N-2)}마심
    => ret = getMaxVolume(N-1) + wine[N];
    getMaxVolume(N-1)에서 N번쨰 wine 선택불가능 case {(N-1, N-2)}마심
    => ret = max(blah blah)
    */
}

int main()
{
    int N, volume;

    memset(wine, -1, sizeof(wine));
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &volume);
        wine[i] = volume;
    }
    printf("%d", getMaxVolume(N));
}