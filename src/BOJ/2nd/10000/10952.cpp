#include <stdio.h>

int main()
{
    int A, B;

    while (scanf("%d %d", &A, &B) != EOF)
    {
        if (A + B)
        {
            printf("%d\n", A + B);
        }
        else
            break;
    }

    return 0;
}