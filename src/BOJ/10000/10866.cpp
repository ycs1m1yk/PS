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

// 다음문제: 10808

using namespace std;
const int MAX_DEQUEUE_SIZE = 100000;

typedef struct node
{
    NODE *next;
    int data;
} NODE;

class Dequeue
{
private:
    NODE *front, *back;
    int length = 0;

public:
    Dequeue();

    int getFront();
    int getBack();
    int getSize();

    void pushFront(int data);
    void pushBack(int data);
    int popFront();
    int popBack();
    bool isEmpty();
};

Dequeue::Dequeue()
{
    front = back = NULL;
}

int Dequeue::getFront()
{
    if (isEmpty())
        return -1;
    else
        return front->data;
}
int Dequeue::getBack()
{
    if (isEmpty())
        return -1;
    else
        return back->data;
}
int Dequeue::getSize()
{
    return size;
}

void Dequeue::pushFront(int data)
{
    NODE newNode = new NODE;
    newNode->data = data;
    newNode->next = NULL;
}

int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        char op[11];
        scanf("%s", op);
        /*
        if (!strcmp(op, "push_front")) // 수정할것
        {
            int data;
            scanf("%d", &data);
            // queue_full은 생략
            back++;
            dequeue[back] = data;
            continue;
        }
        if (!strcmp(op, "push_back")) // 수정할것
        {
            int data;
            scanf("%d", &data);
            // dequeue_full은 생략
            back++;
            dequeue[back] = data;
            continue;
        }
        if (!strcmp(op, "pop_front")) // 수정할것
        {
            if (front == back)
                printf("-1\n");
            else
            {
                printf("%d\n", dequeue[front + 1]);
                front++;
            }

            continue;
        }
        if (!strcmp(op, "pop_back")) // 수정할것
        {
            if (front == back)
                printf("-1\n");
            else
            {
                printf("%d\n", dequeue[front + 1]);
                front++;
            }

            continue;
        }
        if (!strcmp(op, "size"))
        {
            printf("%d\n", back - front);
            continue;
        }
        if (!strcmp(op, "empty"))
        {
            if (front == back)
                printf("1\n");
            else
                printf("0\n");
            continue;
        }
        if (!strcmp(op, "front"))
        {
            if (back == front)
                printf("-1\n");
            else
                printf("%d\n", dequeue[front + 1]);
            continue;
        }
        if (!strcmp(op, "back"))
        {
            if (back == front)
                printf("-1\n");
            else
                printf("%d\n", dequeue[back]);
            continue;
        }
        */
    }
}