#include <iostream>
using namespace std;

class QueuLinkedListNode
{
private:
    /* data */
public:
    QueuLinkedListNode *prev;
    QueuLinkedListNode *next;
    int data;
    QueuLinkedListNode(/* args */);
    QueuLinkedListNode(int data);
    ~QueuLinkedListNode();
};

QueuLinkedListNode::QueuLinkedListNode(/* args */)
{
}

QueuLinkedListNode::QueuLinkedListNode(int data)
{
    this->data = data;
}

QueuLinkedListNode::~QueuLinkedListNode()
{
}

class QueuLinkedList
{
private:
    /* data */
public:
    QueuLinkedListNode *front;
    QueuLinkedListNode *rare;
    QueuLinkedList(/* args */);
    ~QueuLinkedList();
    void enQueue(int data);
    int deQueue();
    void display();
    int getfront();
    int getRear();
};

QueuLinkedList::QueuLinkedList(/* args */)
{
    front = NULL;
    rare = NULL;
}

QueuLinkedList::~QueuLinkedList()
{
}

void QueuLinkedList::enQueue(int data)
{
    QueuLinkedListNode *newNode=new QueuLinkedListNode(data);
    if (front==NULL&&rare==NULL)
    {
        front=rare=newNode;
        
    }else
    {
        newNode->prev=rare;
        rare->next=newNode;
        newNode->next=NULL;
        rare=newNode;
    }
    
    
    
}

int QueuLinkedList::deQueue()
{
    if (front==NULL&&rare==NULL)
    {
        throw "Stack Is Empty";
        return 0;
    }else
    {
        QueuLinkedListNode * temp;
        temp=front;
        int data=front->data;
        front=front->next;
        delete temp;
        return data;
    }
    
    
    

}

void QueuLinkedList::display()
{
    if (front==NULL&&rare==NULL)
    {
        throw "Stack Is Empty";
        return;
    }
    QueuLinkedListNode * temp;
    temp=front;
    while (front!=NULL)
    {
        cout<<front->data<<endl;
        front=front->next;
    }

    
}

int QueuLinkedList::getfront()
{
    if (front==NULL)
    {
        throw "Front is null ";
        return 0;
    }
    else
    {
        return front->data;
    }
    
    
  
}

int QueuLinkedList::getRear()
{
       if (rare==NULL)
    {
        throw "rare is null ";
        return 0;
    }
    else
    {
        return rare->data;
    }
    
    
}

int main(int argc, char const *argv[])
{
    
    QueuLinkedList q;
    
    q.enQueue(4);
    q.enQueue(5);
    q.enQueue(6);
    q.display();
    q.enQueue(4);
    q.enQueue(5);
    q.enQueue(6);
    q.display();
    //      try
    // {
    //     // q.display();
    //     // q.getfront();
    //     q.getRear();
    // }
    // catch (const char *c)
    // {
    //     cout << c << '\n';
    // }
    // q.enQueue(1);
    // q.enQueue(2);
    // q.enQueue(3);
    //   try
    // {
    //     // q.display();
    //     // cout<<q.getfront()<<endl;
    //     // cout<<q.getRear()<<endl;

    //     // cout<<q.deQueue()<<endl;
    //     // cout<<q.deQueue()<<endl;
    //     // cout<<q.deQueue()<<endl;
    // }
    // catch (const char *c)
    // {
    //     cout << c << '\n';
    // }
    return 0;
}
