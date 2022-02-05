// almost everything about Binary Search Tree
#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node *left, *right;
    Node(int data):data{data},left{NULL},right{NULL}{}
};

class BinarySearchTree{
    Node *root;

    public:
    BinarySearchTree():root{NULL}{}

    Node *getRoot();
    void setRoot(Node*);
    bool isTreeEmpty();
    void insertNode(Node*,int);
    void printPreorder(Node*);
    void pirntInorder(Node*);
    void printPostOrder(Node*);
    void printLevelOrder(Node*,int);
    bool search(Node*, int);
    Node* minValue(Node*);
    int maxValue(Node*);
    int height(Node*);
    Node* deleteNode(Node*,int);
    Node* makeBalancedBST(Node*);
};

Node *BinarySearchTree::getRoot()
{
    return root;
}

void BinarySearchTree::setRoot(Node* parent)
{
    root = parent;
}

bool BinarySearchTree::isTreeEmpty()
{
    return root==NULL;
}

void BinarySearchTree::insertNode(Node *parent, int data)
{
    if(root == NULL) root = new Node(data);
    else if(parent == NULL) parent = new Node(data);
    else if(parent->data == data) return;
    else
    {
        if(parent->data > data)
        {
            if(parent->left == NULL) parent->left = new Node(data);
            else insertNode(parent->left,data);
        }
        else
        {
            if(parent->right == NULL) parent->right = new Node(data);
            else insertNode(parent->right,data);
        }
    }
}

void BinarySearchTree::printPreorder(Node *parent)
{
    if(parent == NULL) return;
    cout << parent->data << " ";
    printPreorder(parent->left);
    printPreorder(parent->right);
}

void BinarySearchTree::pirntInorder(Node *parent)
{
    if(parent == NULL) return;
    pirntInorder(parent->left);
    cout << parent->data << " ";
    pirntInorder(parent->right);
}

void BinarySearchTree::printPostOrder(Node *parent)
{
    if(parent == NULL) return;
    printPostOrder(parent->left);
    printPostOrder(parent->right);
    cout << parent->data << " ";
}

Node* BinarySearchTree::minValue(Node *parent)
{
    if(parent->left == NULL) return parent;
    return minValue(parent->left);
}

int BinarySearchTree::maxValue(Node *parent)
{
    if(parent->right == NULL) return parent->data;
    return maxValue(parent->right);
}

bool BinarySearchTree::search(Node *parent, int key)
{
    if(parent == NULL) return false;
    if(parent->data == key) return true;

    if(parent->data > key) return search(parent->left,key);
    return search(parent->right,key);
}

int BinarySearchTree::height(Node *parent)
{
    if(parent == NULL) return -1;
    return max(height(parent->left), height(parent->right))+1;
}

void BinarySearchTree::printLevelOrder(Node* parent, int level)
{
    if(parent == NULL) return;
    if(level==0) cout << parent->data << " ";
    else
    {
        printLevelOrder(parent->left,level-1);
        printLevelOrder(parent->right,level-1);
    }
}

Node* BinarySearchTree::deleteNode(Node* parent, int key)
{
    if(parent == NULL) return parent;
    if(parent->data > key) parent->left = deleteNode(parent->left,key);
    else if(parent->data < key) parent->right = deleteNode(parent->right,key);
    else
    {
        if(parent->left == NULL and parent->right == NULL)
        {   
            // parent has no children
            delete parent;
            parent=NULL;
        }
        else if(parent->left == NULL) // right child exist
        {
            Node *tmp = parent;
            parent = parent->right;
            delete tmp;
        }
        else if(parent->right == NULL) // left child exist
        {
            Node* tmp = parent;
            parent = parent->left;
            delete tmp;
        }
        else // left and right children exist
        {
            Node *minNode = minValue(parent->right);
            parent->data = minNode->data;
            parent->right = deleteNode(parent->right,minNode->data);
        }
    }
    return parent;
}

Node* BinarySearchTree::makeBalancedBST(Node* parent)
{
    vector<int> inorder;
    auto findInorder = [&inorder](const auto findInorder ,Node* parent){
        if(parent == NULL) return;
        
        findInorder(findInorder,parent->left);
        inorder.push_back(parent->data);
        findInorder(findInorder,parent->right);
    };
    findInorder(findInorder,parent); // find inorder and store it

    auto BBST = [inorder](const auto BBST ,int start, int end)->Node*{
        if(start>end) return NULL;
        int mid=(start+end)/2;
        
        Node* parent = new Node(inorder[mid]);

        parent->left = BBST(BBST,start,mid-1);
        parent->right = BBST(BBST,mid+1,end);

        return parent;
    };

    return BBST(BBST,0,(inorder.size())-1);
}

int main()
{
    int code,h=0;
    BinarySearchTree bst;

    vector<int> tmpo={9,5,14,7,6,8,10,12,15,1,16,17,18,19,20,21,22};
    for(auto &x:tmpo) bst.insertNode(bst.getRoot(),x);

    while(true)
    {
        for(int i=0;i<165;i++) cout << "-"; 
        cout << endl;
        cout << "1. Insert | 2. Preorder | 3. Inorder | 4. Postorder | 5. Levelorder | 6. Check Empty | 7. Search | 8. Min | 9. Max | 10. Height | 11. Delete | 12. Balanced | 0. Exit" << endl; 
        for(int i=0;i<165;i++) cout << "-"; 
        cout << endl;
        
        cin >> code;
        switch (code)
        {
            case 1:
                cout << "Enter data : ";
                int data;
                cin >> data;
                bst.insertNode(bst.getRoot(),data);
            break;
            case 2:
            cout << "Preorder: ";
            bst.printPreorder(bst.getRoot());
            cout << endl;
            break;
            case 3:
            cout << "Inorder: ";
            bst.pirntInorder(bst.getRoot());
            cout << endl;
            break;
            case 4:
            cout << "Postorder: ";
            bst.printPostOrder(bst.getRoot());
            cout << endl;
            break;
            case 5:
                cout << "Levelorder: ";
                h=bst.height(bst.getRoot());
                for(int i=0;i<=h;i++) bst.printLevelOrder(bst.getRoot(),i);
                cout << endl;
                break;
            case 6:
                cout << "Tree is " << (bst.isTreeEmpty() ? "" : "Not ") << "Empty" << endl;
                break;
            case 7:
                cout << "Enter key : ";
                int key;
                cin >> key;
                cout << key << " is " << (bst.search(bst.getRoot(),key)? "":"not ") << "found" << endl; 
                break;
            case 8:
                cout << "Minimum value : " << bst.minValue(bst.getRoot())->data << endl;
                break;
            case 9:
                cout << "Maximum value : " << bst.maxValue(bst.getRoot()) << endl;
                break;
            case 10:
                cout << "Height of this tree is : " << bst.height(bst.getRoot()) << endl;
                break;
            case 11:
                cout << "Enter key you want to delete : ";
                int key2;
                cin >> key2;
                bst.setRoot(bst.deleteNode(bst.getRoot(),key2));
                break;
            case 12:
                bst.setRoot(bst.makeBalancedBST(bst.getRoot()));
                break;
            default:
                return 0;
        }
    }
    return 0;
}
