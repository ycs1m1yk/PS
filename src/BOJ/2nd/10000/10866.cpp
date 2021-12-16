#include <iostream>
#include <cstring>
#define fastio ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

struct Node
{
    int data;
    Node *prev, *next;

    Node(int d, Node *p = nullptr, Node *n = nullptr) : data(d), prev(p), next(n) {}
};
class Deque
{
public:
    Deque();
    ~Deque();

    bool empty();
    void pushFront(int);
    void pushBack(int);
    int getSize();
    int popFront();
    int popBack();
    int getFront();
    int getBack();

private:
    Node *front;
    Node *back;
    int size;
};

Deque::Deque()
{
    front = nullptr;
    back = nullptr;
    size = 0;
}

Deque::~Deque()
{
    while (!empty())
    {
        popBack();
    }
}

bool Deque::empty()
{
    return size == 0;
}

void Deque::pushFront(int X)
{
    if (empty())
    {
        front = back = new Node(X);
        size++;
        return;
    }
    Node *newNode = new Node(X, nullptr, front);
    front->prev = newNode;
    front = newNode;
    size++;
}

void Deque::pushBack(int X)
{
    if (empty())
    {
        front = back = new Node(X);
        size++;
        return;
    }
    Node *newNode = new Node(X, back, nullptr);
    back->next = newNode;
    back = newNode;
    size++;
}

int Deque::getSize()
{
    return size;
}

int Deque::popFront()
{
    if (empty())
        return -1;
    int ret = getFront();
    Node *node = front;
    if(size>1){
        front = front->next;
        delete node;
        front->prev=nullptr;
    }
    else {
        front=back=new Node(ret);
        delete node;
    }
    size--;

    return ret;
}

int Deque::popBack()
{
    if (empty())
        return -1;
    int ret = getBack();
    Node *node = back;
    if(size>1){
        back=back->prev;
        delete node;
        back->next=nullptr;
    }
    else {
        front=back=new Node(ret);
        delete node;
    }
    size--;

    return ret;
}

int Deque::getFront()
{
    if(empty()) return -1;
    return front->data;
}

int Deque::getBack()
{
    if(empty()) return -1;
    return back->data;
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
            dq.pushFront(item);
        }
        else if (strcmp(command, "push_back") == 0)
        {
            int item;
            cin >> item;
            dq.pushBack(item);
        }
        else if (strcmp(command, "pop_front") == 0)
        {
            cout << dq.popFront() << "\n";
        }
        else if (strcmp(command, "pop_back") == 0)
        {
            cout << dq.popBack() << "\n";
        }
        else if (strcmp(command, "size") == 0)
        {
            cout << dq.getSize() << "\n";
        }
        else if (strcmp(command, "empty") == 0)
        {
            if (dq.empty())
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