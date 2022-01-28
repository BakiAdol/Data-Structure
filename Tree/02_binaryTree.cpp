#include <bits/stdc++.h>

using namespace std;

/**
 * Binary tree is a tree that it's each parent has at most 2 children
 * Proper/Strict/Full binary tree's each node contains 0 or 2 children
 * Almost Complete binary tree's all level are filled except last level and seclond last level and last level node are as left as possible
 * Perfect binary tree's all levels are completely filled with 2 children
 * Maximum number of node in a binary tree at level x is 2^x
 * Maximum number of node in a binary tree at height h = 2^0 + 2^1 ... + 2^h = 2^(h+1)-1
 * Left skewed tree's each node contain 0 or only one left child
 * Right skewed tree's ecah node contains 0 or only one right child
 */

struct Node{
    int data;
    Node *left, *right;
    Node(int data):data{data},left{NULL},right{NULL}{}
};

void printBinaryTreeUsingDFS(Node *root)
{
    if(root == NULL) return;

    cout << root->data << " ";

    printBinaryTreeUsingDFS(root->left);
    printBinaryTreeUsingDFS(root->right);
}

// store data in a array as tree
void setDataInTree(char which, int parent, int key, int *tree)
{
    int child = parent*2 + (which=='L' ? 1 :2);
    tree[child] = key;
}

int main()
{
    // create nodes
    Node *root = new Node(1);
    Node *left = new Node(2);
    Node *right = new Node(3);
    Node *left_left = new Node(4);
    Node *left_right = new Node(5);
    Node *right_left = new Node(6);
    Node *right_right = new Node(7);

    // make binary tree
    root->left = left;
    root->right = right;
    
    left->left = left_left;
    left->right = left_right;

    right->left = right_left;
    right->right = right_right;

    printBinaryTreeUsingDFS(root);
    cout << endl;

    // array representation of binary tree
    int tree[100];

    tree[0]=1; // make root

    setDataInTree('L',0,5,tree);
    setDataInTree('R',0,3,tree);
    setDataInTree('L',1,2,tree);
    setDataInTree('R',1,7,tree);

    for(int i=0;i<5;i++)
    {
        cout << tree[i] << " ";
    }
    cout << endl;


    return 0;
}
