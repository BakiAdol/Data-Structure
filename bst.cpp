#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int n)
    {
        data=n;
        left=NULL;
        right=NULL;
    }
};

void insertNode(Node* root, int num)
{
    if(num<root->data)
    {
        if(root->left==NULL) root->left=new Node(num);
        else insertNode(root->left,num);
    }
    else
    {
        if(root->right==NULL) root->right=new Node(num);
        else insertNode(root->right,num);
    }
}

void inorderPrint(Node* root)
{
    if(root!=NULL)
    {
        inorderPrint(root->left);
        cout << root->data << " - ";
        inorderPrint(root->right);
    }
}

void preorderPrint(Node* root)
{
    if(root!=NULL)
    {
        cout << root->data << " - ";
        preorderPrint(root->left);
        preorderPrint(root->right);
    }
}

void postorderPrint(Node* root)
{
    if(root!=NULL)
    {
        postorderPrint(root->left);
        postorderPrint(root->right);
        cout << root->data << " - ";
    }
}

int main()
{
    int numbers,num;
    cin >> numbers;
    Node* root=NULL;
    for(int i=0;i<numbers;i++)
    {
        cin >> num;
        if(root==NULL) root=new Node(num);
        else insertNode(root,num);
    }
    cout << "Inorder : ";
    inorderPrint(root);
    cout << endl;

    cout << "Preorder : ";
    preorderPrint(root);
    cout << endl;

    cout << "Postorder : ";
    postorderPrint(root);
    cout << endl;

    return 0;
}
