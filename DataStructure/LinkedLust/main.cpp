#include <iostream>
using namespace std ;
#include "linked.h"

int main()
{
    LinkedList l;
    l.add(5);
    l.add(6);
    
    l.add(7);
    l.add(8);
    // l.insertAfter(7,10);
    // l.insertBefore(7,14);
    // l.printLinkedList();
    
    cout<<l.getDataByIndex(0)<<endl;
    // cout<<l.getCount()<<endl;

    return 0;
}
