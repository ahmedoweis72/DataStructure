#include <iostream>
using namespace std;
#include "linked.h"

class Newfunc
{
private:
    /* data */
public:
    Newfunc(/* args */);
    ~Newfunc();
    void swapNodes(Node* node1, Node* node2) {
        if (node1->data == node2->data) return;

      int temp;
      if (node1->data>node2->data)
      {
        temp=node1->data;
        node1->data=node2->data;
        node2->data=temp;
      }
      
    }
    
int linearSearch(int search, int *arr, int size)
{
    int index = -1;
    LinkedList l;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == search)
        {
            l.add(i);
            index = i;
        }
    }
    l.printLinkedList();
    return index;
}

int binarySearech(int search, int *arr, int size)
{
    int start = 0;
    int end = size - 1;
    int mid = 0;
    if (search >= start && search <= end)
    {
        while (start <= end)
        {
            mid = (start + end) / 2;
            if (search == arr[mid])
            {
                return mid;
            }
            else if (search > arr[mid])
            {
                start = mid + 1;
            }
            else if (search < arr[mid])
            {
                end = mid - 1;
            }
        }
    }
    return -1;
}

void bubleSort(LinkedList &list) {
    if (!list.head) return; 

    bool swapped;
    do {
        swapped = false;
        Node* current = list.head;

        while (current && current->next) {
            if (current->data > current->next->data) {
                swapNodes(current, current->next);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}


};

Newfunc::Newfunc(/* args */)
{
}

Newfunc::~Newfunc()
{
}





int main()
{
    Newfunc f;
    // Linear Search run
    /* int arr[]={1,2,5,5,5,6,7,8,9,10};
    int size =sizeof(arr)/sizeof(arr[0]);
   int result= f.linearSearch(5,arr,size);
   result==-1?cout<<"Not Found"<<endl:cout<<"Found"<<result<<endl; */

    // BinarySarch
    /*     int arr[] = {1, 2, 3, 4, 5, 6, 8, 8, 9, 10};
        int size = sizeof(arr) / sizeof(arr[0]);
        int result = f.binarySearech(11, arr, size);
        result==-1?cout<<"Not Found"<<endl:cout<<"Found"<<result<<endl; */

    
    LinkedList l;
    l.add(5);
    l.add(7);
    l.add(6);
    // l.printLinkedList();
    f.bubleSort(l);
    l.printLinkedList();

    return 0;
}
