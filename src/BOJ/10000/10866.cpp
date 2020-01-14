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
const int MAX_DEQUE_SIZE = 10001;

typedef struct node
{
    int data;
    struct node *prev, *next;
} NODE;

class Deque
{
private:
    NODE *front, *back;
    int size;

public:
    Deque();

    int getFront();
    int getBack();
    int getSize();

    void pushFront(int data);
    void pushBack(int data);
    int popFront();
    int popBack();
    bool isEmpty();
};

Deque::Deque()
{
    front = back = NULL;
    size = 0;
}

int Deque::getFront()
{
    if (isEmpty())
        return -1;
    else
        return front->data;
}
int Deque::getBack()
{
    if (isEmpty())
        return -1;
    else
        return back->data;
}
int Deque::getSize()
{
    return size;
}

void Deque::pushFront(int data)
{
    NODE *newNode = new struct node;
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (front == NULL)
    {
        front = newNode;
        back = newNode;
    }
    else
    {
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }
    size++;
}
void Deque::pushBack(int data)
{
    NODE *newNode = new NODE;
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (back == NULL)
    {
        front = newNode;
        back = newNode;
    }
    else
    {
        newNode->prev = back;
        back->next = newNode;
        back = newNode;
    }
    size++;
}
int Deque::popFront()
{
    if (isEmpty())
        return -1;
    else
    {
        int ret = front->data;
        node *tmp = front;
        front = front->next;
        if (front == NULL)
            back = NULL;
        else
            front->prev = NULL;
        free(tmp);
        size--;
        return ret;
    }
}
int Deque::popBack()
{
    if (isEmpty())
        return -1;
    else
    {
        int ret = back->data;
        node *tmp = back;
        back = back->prev;
        if (back == NULL)
            front = NULL;
        else
            back->next = NULL;
        free(tmp);
        size--;
        return ret;
    }
}
bool Deque::isEmpty()
{
    return front == NULL;
}

int main()
{
    int N;
    Deque dq;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        char op[11];
        scanf("%s", op);
        if (!strcmp(op, "push_front")) // 수정할것
        {
            int data;
            scanf("%d", &data);
            // queue_full은 생략
            dq.pushFront(data);
            continue;
        }
        if (!strcmp(op, "push_back")) // 수정할것
        {
            int data;
            scanf("%d", &data);
            // queue_full은 생략
            dq.pushBack(data);
            continue;
        }
        if (!strcmp(op, "pop_front")) // 수정할것
        {
            printf("%d\n", dq.popFront());
            continue;
        }
        if (!strcmp(op, "pop_back")) // 수정할것
        {
            printf("%d\n", dq.popBack());
            continue;
        }
        if (!strcmp(op, "size"))
        {
            printf("%d\n", dq.getSize());
            continue;
        }
        if (!strcmp(op, "empty"))
        {
            printf("%d\n", dq.isEmpty() ? 1 : 0);
            continue;
        }
        if (!strcmp(op, "front"))
        {
            printf("%d\n", dq.getFront());
            continue;
        }
        if (!strcmp(op, "back"))
        {
            printf("%d\n", dq.getBack());
        }
    }
}