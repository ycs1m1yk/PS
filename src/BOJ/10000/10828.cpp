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

const int MAX_STACK_SIZE = 10000;

int top = -1;

void push(int stack[], int data)
{
    top++;
    stack[top] = data;
}
int empty(int stack[])
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int pop(int stack[])
{
    if (empty(stack))
    {
        return -1;
    }
    else
    {
        int ret = stack[top];
        top--;
        return ret;
    }
}
int size(int stack[])
{
    return (top + 1);
}
int returnTop(int stack[])
{
    if (!empty(stack))
    {
        return stack[top];
    }
    else
    {
        return -1;
    }
}
int main()
{
    int N;
    int stack[MAX_STACK_SIZE] = {0};
    string opArr[4] = {"pop", "size", "empty", "top"};
    int (*fpArr[4])(int[]) = {pop, size, empty, returnTop};
    scanf("%d", &N);
    N++; // 자꾸 getline을 N-1번만 하길래 넣었는데 원인을 모르겠다.
    while (N--)
    {
        string op;
        getline(cin, op);
        if (op.find("push") != string::npos)
        {
            string::size_type numPos = op.find_first_not_of("push");
            push(stack, stoi(op.substr(numPos)));
            continue;
        }
        else
        {
            if (!op.compare(opArr[0]))
            {
                printf("%d\n", fpArr[0](stack));
                continue;
            }
            if (!op.compare(opArr[1]))
            {
                printf("%d\n", fpArr[1](stack));
                continue;
            }
            if (!op.compare(opArr[2]))
            {
                printf("%d\n", fpArr[2](stack));
                continue;
            }
            if (!op.compare(opArr[3]))
            {
                printf("%d\n", fpArr[3](stack));
                continue;
            }
        }
    }
}