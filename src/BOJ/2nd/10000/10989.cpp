#include <iostream>
#include <cstring>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
const int MAX = 10001;
int N, numbers[MAX];

int main()
{
    fastio;
    memset(numbers, 0, sizeof(numbers));
    cin >> N;
    while (N--)
    {
        int input;
        cin >> input;
        numbers[input]++;
    }

    for (int i = 1; i <=MAX; i++)
    {
        for (int j = 0; j < numbers[i]; j++)
        {
            if(numbers[i])
                cout << i << "\n";
        }
    }
}