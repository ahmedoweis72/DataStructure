#include <iostream>
using namespace std;
#include "node.h"

class LinkedList
{
private:
    Node *head;
    Node *tail;
    int counter;

public:
    LinkedList();
    ~LinkedList();
    void add(int data);
    void printLinkedList();
    void insertAfter(int element, int data);
    void insertBefore(int element, int data);
    int getCount();
    int getDataByIndex(int idx);
};

LinkedList::LinkedList()
{
    counter = 0;
    head = NULL;
    tail = NULL;
}
LinkedList::~LinkedList()
{
}
void LinkedList::add(int data)
{
    Node *newNode = new Node(data);
    counter++;
    newNode->index++;
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        newNode->index = 0;
    }
    else if (head == tail)
    {
        newNode->prev = head;
        head->next = newNode;
        tail = newNode;
       
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = NULL;
        tail = newNode;
        
    }
    cout<<newNode->index;
}
void LinkedList::printLinkedList()
{
    Node *cureent = this->head;
    while (cureent != NULL)
    {
        cout << cureent->data << endl;
        cureent = cureent->next;
    }
}
void LinkedList::insertAfter(int element, int data)
{
    Node *newNode = new Node(data);
    Node *cureent = this->head;
    while (cureent != NULL)
    {

        if (cureent->data == element)
        {
            newNode->next = cureent->next;
            newNode->prev = cureent;
            cureent->next = newNode;
        }

        cureent = cureent->next;
    }
}
void LinkedList::insertBefore(int element, int data)
{
    Node *current = head;
    while (current != NULL)
    {
        if (current->data == element)
        {
            Node *newNode = new Node(data);
            newNode->next = current;
            newNode->prev = current->prev;

            if (current->prev != NULL)
            {
                current->prev->next = newNode;
            }
            else
            {
                head = newNode;
            }
            current->prev = newNode;
            break;
        }
        current = current->next;
    }
}

int LinkedList::getCount()
{
    int i = 0;
    Node *cureent = this->head;
    while (cureent != NULL)
    {
        i++;
        cureent = cureent->next;
    }
    return i;
}

int LinkedList::getDataByIndex(int idx)
{
    int data;
    Node *cureent=this->head;
    while (cureent!=NULL)
    {
        if (cureent->index==idx)
        {
            data=cureent->data;
        }
        cureent=cureent->next;
    }
    

    
    return data;
}
