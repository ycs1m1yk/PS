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
int main()
{
    int A, B, m, sum = 0, input;
    cin >> A >> B;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> input;
        sum += input * pow(A, m - i - 1);
    }
    stack<int> S;
    while (sum)
    {
        S.push(sum % B);
        sum /= B;
        cout << sum << "\n";
    }
}