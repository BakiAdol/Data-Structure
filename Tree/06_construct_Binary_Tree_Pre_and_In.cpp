#include <bits/stdc++.h>

using namespace std;

struct Node{
    char data;
    Node* left, *right;
    Node(char data):data{data},left{NULL},right{NULL}{}
};

Node *consBTreeFromInandPreRecursive(vector<char> &In, vector<char> &Pre)
{
    map<char,int> nodePosition;
    for(int i=0;i<(int)In.size();i++)
    {
        nodePosition[In[i]]=i;
    }
    int preorderPos=-1;

    auto constructTree = [&](const auto constructTree ,int startPos, int endPos)->Node*
    {
        if(startPos > endPos) return NULL;

        Node *newNode = new Node(Pre[++preorderPos]);
        int inorderPos = nodePosition[Pre[preorderPos]];
        if(startPos == endPos) return newNode;

        newNode->left = constructTree(constructTree,startPos,inorderPos-1);
        newNode->right = constructTree(constructTree,inorderPos+1,endPos);

        return newNode;
    };

    return constructTree(constructTree,0,In.size()-1);
}

Node *consBTreeFromInandPreIterative(vector<char> &In, vector<char> &Pre)
{
    Node *root = new Node(Pre[0]);
    Node *prev = root;
    int len = Pre.size();
    int preorderPos = 1, inorderPos = 0, flag = 0;
    stack<Node*> st;
    st.push(prev);

    while(preorderPos < len)
    {
        if(!st.empty() and st.top()->data==In[inorderPos])
        {
            prev = st.top();
            st.pop();
            inorderPos++;
            flag = 1;
        }
        else{
            Node *newNode = new Node(Pre[preorderPos++]);
            if(flag==0)
            {
                prev->left = newNode;
                prev = prev->left;
            }
            else{
                prev->right = newNode;
                prev = prev->right;
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
    vector<char> pre={'A','D','H','L','P','Z','C','E'};
    
    // recursion method
    Node *treeA = consBTreeFromInandPreRecursive(in,pre);

    cout << "Pre order: "; preOrderPrint(treeA);cout << endl;
    cout << "In order: "; inorderPrint(treeA);cout << endl;
    cout << "Post order: "; postOrderPrint(treeA);cout << endl << endl;

    // iterative method
    Node *treeB = consBTreeFromInandPreIterative(in,pre);

    cout << "Pre order: "; preOrderPrint(treeB);cout << endl;
    cout << "In order: "; inorderPrint(treeB);cout << endl;
    cout << "Post order: "; postOrderPrint(treeB);cout << endl;

    return 0;
}
