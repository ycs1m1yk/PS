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
    int A, B, C;
    cin >> A >> B >> C;

    cout << (A + B) % C << "\n";
    cout << (A % C + B % C) % C << "\n";
    cout << (A * B) % C << "\n";
    cout << (A % C * B % C) % C << "\n";
}