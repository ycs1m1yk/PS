#include <iostream>
#include <cmath>

using namespace std;
const int MAX = 100000;
int N, K;

int solve(int here, int target)
{
    int ret = 0;
    if (here == target)
        return ret = 0;

    if (here == 0) // only here+1 case
    {
        ret = solve(here + 1, target) + 1;
    }
    else if (2 * here > MAX) // no 2*here case
    {
        if (here + 1 > MAX) // no here+1 case
        {
            // ret = solve(here - 1, target) + 1;
            ret = target - here;
        }
        else
        {
            ret = min(solve(here + 1, target) + 1, solve(here - 1, target) + 1);
        }
    }
    else if (here > target) // only here-1 case
    {
        cout << "here>target: " << here << "\n";
        ret = target - here;
    }
    else
    {
        cout << "else: " << here << "\n";
        if (abs(target - 2 * here) + 1 > abs(target - here))
        {
            ret = min(abs(target - here), solve(here - 1, target) + 1);
        }
        else
        {
            ret = min(solve(here + 1, target) + 1, solve(2 * here, target) + 1);
            ret = min(ret, solve(here - 1, target) + 1);
        }
    }

    return ret;
}

int main()
{
    cin >> N >> K;

    int result = solve(N, K);
    cout << result;
}