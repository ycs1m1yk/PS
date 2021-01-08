#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> seq(1, 0);

int main()
{
    int N;
    scanf("%d", &N);

    int input;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &input);
        vector<int>::iterator l_b = lower_bound(seq.begin(), seq.end(), input);
        if (input > seq.back())
        {
            seq.push_back(input);
        }
        else if (l_b == --seq.end())
        {
            *l_b = input;
        }
    }

    printf("%d\n", seq.size() - 1);

    vector<int>::iterator it;
    for (it = ++seq.begin(); it != seq.end(); it++)
    {
        printf("%d ", *it);
    }
}