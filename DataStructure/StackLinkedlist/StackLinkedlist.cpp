#include <iostream>
using namespace std;

class StackLinkedNode
{
private:
public:
    StackLinkedNode *prev;
    int data;
    StackLinkedNode(/* args */);
    StackLinkedNode(int data);
    ~StackLinkedNode();
};

StackLinkedNode::StackLinkedNode(/* args */)
{
}

StackLinkedNode::StackLinkedNode(int data)
{
    this->data = data;
    prev = NULL;
}

StackLinkedNode::~StackLinkedNode()
{
}

class StackLinkedlist
{
private:
    StackLinkedNode *tail;

public:
    StackLinkedlist(/* args */);
    ~StackLinkedlist();
    void Push(int data);
    int pop(int &data);
    int peek();
    void display();
};

StackLinkedlist::StackLinkedlist(/* args */)
{
    tail = NULL;
}

StackLinkedlist::~StackLinkedlist()
{
}

void StackLinkedlist::Push(int data)
{
    StackLinkedNode *newNode = new StackLinkedNode(data);
    if (tail == NULL)
    {
        tail = newNode;
    }
    else
    {
        newNode->prev = tail;
        tail = newNode;
    }
}

int StackLinkedlist::pop(int &data)
{
    if (tail == NULL)
    {
        return 0;
    }
    else
    {
        StackLinkedNode *temp;
        temp = tail;
        tail = tail->prev;
        data = temp->data;
        delete temp;
        return 1;
    }
}

int StackLinkedlist::peek()
{
    if (tail == NULL)
    {
        return 0;
    }
    else
    {
        return tail->data;
    }
}

void StackLinkedlist::display()
{
    if (tail == NULL)
    {
        throw "Stack is empty";
    }
    else
    {
        while (tail != NULL)
        {
            cout << tail->data << endl;
            tail = tail->prev;
        }
    }
}

int main(int argc, char const *argv[])
{
    int data = 0;
    StackLinkedlist s;
    try
    {
        s.display();
    }
    catch (const char *c)
    {
        cout << c << '\n';
    }

    s.Push(5);
    s.Push(6);
    s.Push(7);
    s.Push(8);
    s.Push(9);
    try
    {
        s.display();
    }
    catch (const char *c)
    {
        cout << c << '\n';
    }
    s.peek() ? cout << s.peek() << endl : cout << "Stack is empty" << endl;
    s.pop(data) ? cout << "poped" << endl : cout << "Stack is empty" << endl;
    return 0;
}
