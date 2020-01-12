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
const int MAX_QUEUE_SIZE = 100000;

int main()
{
    int N, front = -1, rear = -1;
    int queue[MAX_QUEUE_SIZE] = {0};
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        char op[6];
        scanf("%s", op);
        if (!strcmp(op, "push"))
        {
            int data;
            scanf("%d", &data);
            // queue_full은 생략
            rear++;
            queue[rear] = data;
            continue;
        }
        if (!strcmp(op, "pop"))
        {
            if (front == rear)
                printf("-1\n");
            else
            {
                printf("%d\n", queue[front + 1]);
                front++;
            }

            continue;
        }
        if (!strcmp(op, "size"))
        {
            printf("%d\n", rear - front);
            continue;
        }
        if (!strcmp(op, "empty"))
        {
            if (front == rear)
                printf("1\n");
            else
                printf("0\n");
            continue;
        }
        if (!strcmp(op, "front"))
        {
            if (rear == front)
                printf("-1\n");
            else
                printf("%d\n", queue[front + 1]);
            continue;
        }
        if (!strcmp(op, "back"))
        {
            if (rear == front)
                printf("-1\n");
            else
                printf("%d\n", queue[rear]);
            continue;
        }
    }
}