#include <iostream>
#include <cstring>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
const int MAX_QUEUE_SIZE = 10001;

class Queue
{
public:
    int queue[MAX_QUEUE_SIZE];
    int front = 0;
    int back = 0;

    void push(int X);
    int pop();
    int size();
    bool isEmpty();
    int getFront();
    int getBack();
};

void Queue::push(int X)
{
    this->queue[this->back++] = X;
}

int Queue::pop()
{
    if (this->isEmpty())
        return -1;

    this->front += 1;
    return this->queue[this->front-1];
}

int Queue::size()
{
    return this->back - this->front;
}

bool Queue::isEmpty()
{
    return this->front == this->back;
}

int Queue::getFront()
{
    return this->queue[this->front];
}

int Queue::getBack()
{
    return this->queue[this->back-1];
}

int main()
{
    fastio;
    int N;
    Queue q;
    char command[6];

    cin>>N;
    while (N--)
    {
        cin >> command;
        if (strcmp(command, "pop")==0)
        {
            cout << q.pop() << "\n";
        }
        else if (strcmp(command, "size")==0)
        {
            cout << q.size() << "\n";
        }
        else if (strcmp(command, "empty")==0)
        {
            if(q.isEmpty()){
                cout << 1 << "\n";
            }
            else{
                cout << 0 << "\n";
            }
        }
        else if (strcmp(command, "front")==0)
        {
            cout << q.getFront() << "\n";
        }
        else if (strcmp(command, "back")==0)
        {
            cout << q.getBack() << "\n";
        }
        else
        {
            int item;
            cin>> item;
            q.push(item);
        }
    }
}
