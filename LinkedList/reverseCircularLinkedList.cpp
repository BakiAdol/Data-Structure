#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int data):data{data},next{NULL}{}
};

void printCircularLinkedList(Node *root)
{
    Node *tmp = root;
    if(tmp != NULL)
    {
        do{
            cout << tmp->data << " ";
            tmp = tmp->next;
        }while(tmp != root);
    }
    cout << endl;
}

Node *reverseCircularLinkedListIterative(Node *root)
{
    Node *last = root;
    Node *prev = root;
    Node *first = root->next;

    if(first==last) return root;

    while(first != last)
    {
        root = first;
        first = first->next;
        root->next = prev;
        prev = root;
    }
    last->next = root;

    return root;
}

Node *reverseCircularLinkedListRecursive(Node *root, Node *run)
{
    if(run->next == root) return run;

    root = reverseCircularLinkedListRecursive(root,run->next);
    Node *tmp = run->next;
    run->next = root;
    tmp->next = run;

    return root;
}

int main()
{
    Node *root = new Node(1);
    root->next = new Node(2);
    root->next->next = new Node(3);
    root->next->next->next = new Node(4);
    root->next->next->next->next = root;

    printCircularLinkedList(root);

    root = reverseCircularLinkedListRecursive(root,root);

    printCircularLinkedList(root);


    return 0;
}

