#include <iostream>
#include <cstring>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
const int MAX_DEQUE_SIZE = 10001;

class Deque
{
    int* arr;
    int front;
    int back;

public:
    Deque();

    void push_front(int X);
    void push_back(int X);
    int pop_front();
    int pop_back();
    int getSize();
    bool isEmpty();
    int getFront();
    int getBack();
};

Deque::Deque(){
    arr = new int[MAX_DEQUE_SIZE];
    front=back=0;
}

void Deque::push_front(int X)
{
    arr[front] = X;
    front = (front - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
}
void Deque::push_back(int X)
{
    back = (back + 1) % MAX_DEQUE_SIZE;
    arr[back] = X;
}

int Deque::pop_front()
{
    if (isEmpty())
        return -1;

    int ret = getFront();
    front = (front + 1) % MAX_DEQUE_SIZE;
    return ret;
}
int Deque::pop_back()
{
    if (isEmpty())
        return -1;

    int ret = getBack();
    back = (back - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
    return ret;
}

int Deque::getSize()
{
    return (back - front + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
}

bool Deque::isEmpty()
{
    return front == back;
}

int Deque::getFront()
{
    if (isEmpty())
        return -1;
    return arr[(front + 1) % MAX_DEQUE_SIZE];
}

int Deque::getBack()
{
    if (isEmpty())
        return -1;
    return arr[back];
}

int main()
{
    fastio;
    int N;
    Deque dq;

    cin >> N;
    while (N--)
    {
        char command[11];
        cin >> command;
        if (strcmp(command, "push_front") == 0)
        {
            int item;
            cin >> item;
            dq.push_front(item);
        }
        else if (strcmp(command, "push_back") == 0)
        {
            int item;
            cin >> item;
            dq.push_back(item);
        }
        else if (strcmp(command, "pop_front") == 0)
        {
            cout << dq.pop_front() << "\n";
        }
        else if (strcmp(command, "pop_back") == 0)
        {
            cout << dq.pop_back() << "\n";
        }
        else if (strcmp(command, "size") == 0)
        {
            cout << dq.getSize() << "\n";
        }
        else if (strcmp(command, "empty") == 0)
        {
            if (dq.isEmpty())
                cout << "1\n";
            else
                cout << "0\n";
        }
        else if (strcmp(command, "front") == 0)
        {
            cout << dq.getFront() << "\n";
        }
        else if (strcmp(command, "back") == 0)
        {
            cout << dq.getBack() << "\n";
        }
    }
}