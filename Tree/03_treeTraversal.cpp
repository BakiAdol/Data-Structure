#include <bits/stdc++.h>

using namespace std;

/**
 * Binary tree traversal
 * Inorder : left root right
 * Preorder : root left right
 * Postorder : left roght root
 */

struct Node{
    int data;
    Node *left, *right;
    Node(int data):data{data},left{NULL},right{NULL}{}
};

void addNodeInCompleteBinaryTree(Node *root, int key)
{
    queue<Node*> q;
    q.push(root);
    while(true)
    {
        Node *tmp = q.front();
        q.pop();

        if(tmp->left == NULL)
        {
            tmp->left = new Node(key);
            return;
        }

        if(tmp->right == NULL)
        {
            tmp->right = new Node(key);
            return;
        }

        q.push(tmp->left);
        q.push(tmp->right);
    }
}

void preorderTraversal(Node *root)
{
    if(root == NULL) return;

    cout << root->data << " ";

    preorderTraversal(root->left);

    preorderTraversal(root->right);
}

void inorderTraversal(Node *root)
{
    if(root == NULL) return;

    inorderTraversal(root->left);

    cout << root->data << " ";
    
    inorderTraversal(root->right);
}

void postorderTraversal(Node *root)
{
    if(root == NULL) return;

    postorderTraversal(root->left);
    
    postorderTraversal(root->right);
    
    cout << root->data << " ";
}



int main()
{
    Node *root = new Node(1);
    

    for(int i=2;i<11;i++)
    {
        // insert node in the complete binary tree
        addNodeInCompleteBinaryTree(root,i);
    }

    cout << "Preorder traversal : ";
    preorderTraversal(root);
    cout << endl;

    cout << "Inorder traversal : ";
    inorderTraversal(root);
    cout << endl;

    cout << "postorder traversal : ";
    postorderTraversal(root);
    cout << endl;

    return 0;
}
