#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> series(1, 0);
/*
    TEST CASE
        
        6
        10 20 10 30 20 50

        10
        1 2 3 100 101 102 10 11 12 13
*/
int main()
{
    int n;
    scanf("%d", &n);

    int input;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &input);
        if (series.back() < input)
        {
            series.push_back(input);
        }
        else
        {
            *lower_bound(series.begin(), series.end(), input) = input;
        }
    }

    printf("%d", series.size() - 1);
}