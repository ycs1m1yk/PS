#include <iostream>
#include <cstring>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
const int MAX_DEQUE_SIZE = 10000;

class Deque
{
public:
    int Deque[MAX_DEQUE_SIZE];
    int front = 0;
    int back = 0;

    void push_front(int X);
    void push_back(int X);
    int pop_front();
    int pop_back();
    int size();
    bool isEmpty();
    int getFront();
    int getBack();
};

void Deque::push_front(int X)
{
    /*

        |  | X | X |
         ก่
        front
    
    */
    this->Deque[this->front] = X;
    this->front = (this->front - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
}
void Deque::push_back(int X)
{
    /*

        | X | X |   |
              ก่
            back
    
    */
    this->back = (this->back + 1) % MAX_DEQUE_SIZE;
    this->Deque[this->back] = X;
}

int Deque::pop_front()
{
    if (this->isEmpty())
        return -1;

    this->front = (this->front + 1) % MAX_DEQUE_SIZE;
    return this->Deque[this->front];
}
int Deque::pop_back()
{
    if (this->isEmpty())
        return -1;

    this->back = (this->back - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
    return this->Deque[(this->back + 1) % MAX_DEQUE_SIZE];
}

int Deque::size()
{
    return (this->back - this->front + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
}

bool Deque::isEmpty()
{
    return this->front == this->back;
}

int Deque::getFront()
{
    if (this->isEmpty())
        return -1;
    return this->Deque[(this->front + 1) % MAX_DEQUE_SIZE];
}

int Deque::getBack()
{
    if (this->isEmpty())
        return -1;
    return this->Deque[this->back];
}

int main()
{
    fastio;
    int N;
    Deque dq;
    char command[10];

    cin >> N;
    while (N--)
    {
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
            cout << dq.size() << "\n";
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