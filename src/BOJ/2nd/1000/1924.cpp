#include <cstdio>

int main()
{

    int daysInMonth[13] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char *days[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

    int x, y, totalDays = 0;
    scanf("%d %d", &x, &y);

    for (int i = 0; i < x - 1; i++)
    {
        totalDays += daysInMonth[i];
    }
    totalDays+=y-1;

    printf("%s", days[totalDays%7]);

    return 0;
}