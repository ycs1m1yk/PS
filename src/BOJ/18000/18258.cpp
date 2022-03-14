#include <cstdio>
#include <queue>
#include <string>

using namespace std;

int N;
queue<int> q;
int main()
{
    scanf("%d", &N);
    while (N--)
    {
        char command[6];
        scanf("%s", &command);

        if (command[1] == 'u')
        {
            int X;
            scanf("%d", &X);
            q.push(X);
        }
        else if (command[0] == 'p')
        {
            if (q.empty())
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n", q.front());
                q.pop();
            }
        }
        else if (command[0] == 's')
        {
            printf("%d\n", q.size());
        }
        else if (command[0] == 'e')
        {
            printf("%d\n", q.empty());
        }
        else if (command[0] == 'f')
        {
            printf("%d\n", q.empty() ? -1 : q.front());
        }
        else if (command[0] == 'b')
        {
            printf("%d\n", q.empty() ? -1 : q.back());
        }
    }
}