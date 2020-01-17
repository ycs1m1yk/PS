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

int getGCD(int n1, int n2)
{
    int ret = 0;
    vector<int> v;
    int lowNum = min(n1, n2);
    int highNum = max(n1, n2);
    for (int i = lowNum; i > 0; i--)
    {
        if (lowNum % i == 0)
        {
            v.push_back(i);
        }
    }
    for (auto n : v)
    {
        if (highNum % n == 0)
        {
            ret = n;
            break;
        }
    }
    return ret;
}
int getLCM(int n1, int n2, int gcd)
{
    int ret;
    return ret = gcd * (n1 / gcd) * (n2 / gcd);
}

int main()
{
    int T, A, B, gcd, lcm;
    cin >> T;
    while (T--)
    {
        cin >> A >> B;
        gcd = getGCD(A, B);
        lcm = getLCM(A, B, gcd);
        cout << lcm << "\n";
    }
}