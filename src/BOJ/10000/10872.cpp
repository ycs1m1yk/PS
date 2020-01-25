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

uint64_t factorial(int N)
{
    if (N == 0)
        return 1;

    return factorial(N - 1) * N;
}
int main()
{
    int N;
    cin >> N;
    cout << factorial(N);
}