#include <iostream>
using namespace std;

class StackArray
{
private:
    int top;
    int size;
    int *st;
    static int counter;

public:
    StackArray(int num = 10)
{
    size = num;
    top = -1;
    st = new int[size];
    counter++;
}
    ~StackArray()
{
    delete[] st;
    counter--;
}  
  void push(int num);
    int pop();
    void viewContent();
};



void StackArray::push(int num)
{
    if (top == size)
    {
        cout << "StackArray Is Full" << endl;
    }
    else
    {
        st[top] = num;
        top++;
    }
}
int StackArray::pop()
{
    int poped = 0;
    if (top < 0)
    {
        cout << "StackArray Is Empty" << endl;
        return poped = -1;
    }
    else
    {
        poped = st[top];
        top--;
    }
    return poped;
}
void StackArray::viewContent()
{
    for (int i = 0; i < size; i++)
    {
        cout << st[i] << endl;
    }
}
int StackArray::counter = 0;

int main()
{
    StackArray s;
    StackArray s1(s);
    int data;
    s.push(5);
    s.push(5);
    s.push(5);
    s.push(5);
    s.push(5);
    s.push(5);
    data=s.pop();

    cout << data << endl;

    s1.viewContent();
    s.viewContent();

    return 0;
}