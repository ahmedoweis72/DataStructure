#include <iostream>
using namespace std;

class QueuArray
{
private:
    int size;
    int *que;
    int rare;
    int front;

public:
    QueuArray(/* args */);
    QueuArray(int size);
    ~QueuArray();

    void enQueue(int data);
    int deQueue(int &data);
    void display();
    int getfront();
    int getRear();
};

QueuArray::QueuArray(/* args */)
{
}

QueuArray::QueuArray(int size)
{
    this->size = size;
    que = new int[size];
    front = -1;
    rare = -1;
}

QueuArray::~QueuArray()
{
    delete[] que;
}

void QueuArray::enQueue(int data)
{
    if (rare < size)
    {
        if (front == -1 && rare == -1)
        {
            front++;
            rare++;
            que[rare] = data;
        }else if (front ==0&&rare<size-1 )
        {
            rare++;
            que[rare]=data;
        }else
            {
                
            if (rare == size - 1)
            {
                rare = 0;
                que[rare] = data;
            }
            else
            {
                rare++;
                que[rare] = data;
            }
            }
           
        
    }
    else
    {
        cout << "queue Is Full" << endl;
    }
}

int QueuArray::deQueue(int &data)
{
    if (rare == -1 && front == -1)
    {
        return 0;
    }
    else
    {
        data = que[front];
        que[front] = 0;
        front++;
        
        return 1;
    }
}

void QueuArray::display()
{
   for (int i = 0; i <size; i++)
    {
        cout<<que[i]<<"\t";
    }
    
    
    
    
    
}

int QueuArray::getfront()
{
    return this->front;
}

int QueuArray::getRear()
{
    return this->rare;
}

int main(int argc, char const *argv[])
{
    QueuArray q(5);
    int data;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);
    q.display();
    // q.enQueue(5);
    q.deQueue(data);
    cout<<endl;
    // q.deQueue(data);
    // cout<<data<<endl;
    // q.deQueue(data);
    // q.deQueue(data);
    // q.enQueue(6);
    // q.enQueue(7);
    // q.display();
    // q.enQueue(8);
    // q.enQueue(8);
    // q.enQueue(8);
    q.display();


    return 0;
}
