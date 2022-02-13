#include <bits/stdc++.h>

using namespace std;

struct Node{
    char data;
    Node* left, *right;
    Node(char data):data{data},left{NULL},right{NULL}{}
};

Node *consBTreeFromInandPostRecursive(vector<char> &In, vector<char> &Post)
{
    map<char,int> nodePosition;
    for(int i=0;i<(int)In.size();i++)
    {
        nodePosition[In[i]]=i;
    }
    int postorderPos=In.size();

    auto constructTree = [&](const auto constructTree ,int startPos, int endPos)->Node*
    {
        if(startPos > endPos) return NULL;

        Node *newNode = new Node(Post[--postorderPos]);
        int inorderPos = nodePosition[Post[postorderPos]];
        if(startPos == endPos) return newNode;

        newNode->right = constructTree(constructTree,inorderPos+1,endPos);
        newNode->left = constructTree(constructTree,startPos,inorderPos-1);
        
        return newNode;
    };

    return constructTree(constructTree,0,In.size()-1);
}

Node *consBTreeFromInandPostIterative(vector<char> &In, vector<char> &Pre)
{
    int len = Pre.size();
    Node *root = new Node(Pre[len-1]);
    Node *prev = root;
    
    int postorderPos = len-1, inorderPos = len-1, flag = 0;
    stack<Node*> st;
    st.push(prev);

    while(postorderPos >= 0)
    {
        if(!st.empty() and st.top()->data==In[inorderPos])
        {
            prev = st.top();
            st.pop();
            inorderPos--;
            flag = 1;
        }
        else{
            Node *newNode = new Node(Pre[--postorderPos]);
            if(flag==0)
            {
                prev->right = newNode;
                prev = prev->right;
            }
            else{
                prev->left = newNode;
                prev = prev->left;
                flag = 0;
            }
            st.push(newNode);
        }
    }

    return root;
}

void inorderPrint(Node *root)
{
    if(root==NULL) return;

    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

void preOrderPrint(Node *root)
{
    if(root==NULL) return;

    cout << root->data << " ";
    preOrderPrint(root->left);
    preOrderPrint(root->right);
}

void postOrderPrint(Node *root)
{
    if(root==NULL) return;

    postOrderPrint(root->left);
    postOrderPrint(root->right);
    cout << root->data << " ";
}

int main()
{
    vector<char> in={'H','D','P','L','A','Z','C','E'};
    vector<char> post={'H','P','L','D','E','C','Z','A'};
    
    // recursion method
    Node *treeA = consBTreeFromInandPostRecursive(in,post);

    cout << "Pre order: "; preOrderPrint(treeA);cout << endl;
    cout << "In order: "; inorderPrint(treeA);cout << endl;
    cout << "Post order: "; postOrderPrint(treeA);cout << endl << endl;

    // iterative method
    Node *treeB = consBTreeFromInandPostIterative(in,post);

    cout << "Pre order: "; preOrderPrint(treeB);cout << endl;
    cout << "In order: "; inorderPrint(treeB);cout << endl;
    cout << "Post order: "; postOrderPrint(treeB);cout << endl;

    return 0;
}
