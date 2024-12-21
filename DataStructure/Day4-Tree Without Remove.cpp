#include <iostream>

using namespace std;
class Node{
    public:
    int data;
    Node * Right;
    Node * Left;
    Node(int _data){
        data=_data;
        Right=Left=NULL;
    }
};
class Tree{
    private:
    Node * root;
    Node * getNodeByData(int data){
        Node * current =root;
        while(current != NULL ){
            if(data == current->data){
                return current;
            }else if(data > current->data){
                current=current->Right;
            }else{
                current=current->Left;
            }
        }
        return NULL;

    }
    Node * getParent(Node * node){
        Node * parent=root;
        while(parent != NULL){
            if(node == parent->Right ||node == parent->Left  ){
                return parent;
            }else if(node->data > parent->data){
                parent=parent->Right;
            }else{
                parent=parent->Left;
            }
        }
        return NULL;

    }
    Node * getMaxRight(Node * node){
        Node * current=node;//Start Point
        while(current->Right != NULL){
            current=current->Right;
        }
        return current;
    }

        void display(Node *node){
            if(node == NULL){
                return ;
            }
            display(node->Left);
            cout<<node->data<<" : ";
            display(node->Right);


        }


    public:
    Node* getRoot(){
        return this->root;
    }
    Tree(){
        root=NULL;
    }
    void add(int data){
        //Create Node
        Node * newNode=new Node(data);
        if(root == NULL){
            root=newNode;
        }
        else{
            Node * current = root;
            Node * parent = NULL;
            while(current != NULL){
                parent=current; //Before Current Jumping
                if(data > current->data){
                    /*if(current->Right == NULL){
                        current->Right=newNode;
                        return;
                    }*/
                    current=current->Right;//
                }else{
                    /*if(current->Left == NULL){
                        current->Left=newNode;
                        return;
                    }*/
                    current=current->Left;
                }
            }
            if(data>parent->data){
               parent->Right=newNode;
            }else{
                parent->Left=newNode;
            }

        }
    }
    int findDataInTree(int data){
        if(getNodeByData(data)== NULL){
            return 0;
        }
            return 1;
    }
    int getParentBydata(int data){
        Node * node = getNodeByData(data);
        if(node == root){
            throw "The Node is Root Not Have Parent";
        }
        if(node != NULL ){
            Node * parent=getParent(node);
            if(parent != NULL){
                return parent->data;
            }
        }else{
            throw " Node Not Found , Not Have Parent";
        }

    }
    int getMaxRightByData(int data){
        Node * node=getNodeByData(data);
        if(node == NULL){
            throw " Node Not Found";
        }
        Node * maxR= getMaxRight(node);
        return maxR->data;
    }

    void displayAll(){
        display(root);
    }
      Node *Findmin(Node *r)
    {
        if (r == NULL)
            return NULL;
        else if (r->Left == NULL)
            return r;
        else
            return Findmin(r->Left);
    }

    Node *Findmax(Node *r)
    {
        if (r == NULL)
            return NULL;
        else if (r->Right == NULL)
            return r;
        else
            return Findmax(r->Right);
    }
    Node *remove(Node *r, int key)
    {
        if (r == NULL) // Empty Tree
            return NULL;
        if (key < r->data) // Item exists in left sub tree
            r->Left = remove(r->Left, key);
        else if (key > r->data) // item exists in Right sub tree
            r->Right = remove(r->Right, key);
        else
        {
            if (r->Left == NULL && r->Right == NULL) // leaf node
                r = NULL;
            else if (r->Left != NULL && r->Right == NULL) // one child on the Left
            {
                r->data = r->Left->data;
                remove (r->Left,key);
                r->Left = NULL;
            }
            else if (r->Left == NULL && r->Right != NULL) // one child on the Right
            {
                r->data = r->Right->data;
                remove (r->Right,key);
                r->Right = NULL;
            }
            else
            {
                Node *max = Findmax(r->Left);
                r->data = max->data;
                r->Left = remove(r->Left, max->data);
            }
        }
        return r;
    }
    void remove( int key){
       root= remove(root,key);
    }
};

int main()
{
    Tree t;
    t.add(50);
    t.add(40);
    t.add(70);
    t.add(30);
    t.add(65);
    t.add(60);
    t.add(35);
    t.add(42);
    t.add(45);
    t.add(48);
    t.add(25);
    t.add(22);
    t.findDataInTree(70)?cout<<"Found \n":cout<<"Not Found \n";//Found
    t.findDataInTree(35)?cout<<"Found \n":cout<<"Not Found \n";//Found
    t.findDataInTree(40)?cout<<"Found \n":cout<<"Not Found \n";//Found
    t.findDataInTree(50)?cout<<"Found \n":cout<<"Not Found \n";//Found
    t.findDataInTree(30)?cout<<"Found \n":cout<<"Not Found \n";//Found
    t.findDataInTree(80)?cout<<"Found \n":cout<<"Not Found \n";//Not Found
    t.findDataInTree(90)?cout<<"Found \n":cout<<"Not Found \n";//Not Found
    try{
        //t.getParentBydata(50);
        cout<<"Parent : "<<t.getParentBydata(35)<<endl;
        cout<<"Max Right : "<<t.getMaxRightByData(50)<<endl;
    }catch(const char * msg){
        cout<<msg;
    }
    t.displayAll();
    cout<<"Before\n";
    t.remove(48);
    cout<<"After\n";
    t.displayAll();
    cout<<"MAx"<<t.Findmax(t.getRoot())->data<<endl;
    cout<<"MIN"<<t.Findmin(t.getRoot())->data<<endl;
    return 0;
}
