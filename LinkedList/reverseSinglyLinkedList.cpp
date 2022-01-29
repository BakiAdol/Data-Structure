#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int data):data{data},next{NULL}{};
};

void printSinglyLinkList(Node *root)
{
    while(root != NULL)
    {
        cout << root->data << " ";
        root = root->next;
    }
    cout << endl;
}

Node *reverseSinglyLinkLIstIterative(Node *root)
{
    if(root->next == NULL) return root;

    Node *prevNode = root;
    root = root->next;
    prevNode->next = NULL;

    while (root->next != NULL)
    {
        Node *tmp = root->next;
        root->next = prevNode;
        prevNode = root;
        root = tmp;
    }
    
    root->next = prevNode;
    return root;
}

Node * reverseSinglyLinkListRecursion(Node *cur)
{
    if(cur->next == NULL) return cur;

    Node * root = reverseSinglyLinkListRecursion(cur->next);
    Node * tmp = cur->next;
    tmp->next = cur;
    cur->next = NULL;

    return root;
}

int main()
{
    Node *root = new Node(1);
    root->next = new Node(5);
    root->next->next = new Node(3);
    root->next->next->next = new Node(10);
    root->next->next->next->next = new Node(2);

    Node * rroot = reverseSinglyLinkListRecursion(root);

    printSinglyLinkList(rroot);

    return 0;
}
