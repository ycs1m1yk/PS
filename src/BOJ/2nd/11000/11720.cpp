#include <cstdio>

int main()
{
    int N;
    scanf("%d", &N);

    int input;
    int sum = 0;
    while (N--)
    {
        scanf("%1d", &input);
        sum += input;
    }

    printf("%d", sum);

    return 0;
}