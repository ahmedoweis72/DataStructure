
class Node
{
private:
   
public:
 Node * next;
    Node * prev;
    int data;
    int index;
    Node();
    Node(int data);
    ~Node();
};

inline Node::Node()
{
}

Node::Node(int data)
{
    this->data=data;
    next=NULL;
    prev=NULL;
}

Node::~Node()
{
}
