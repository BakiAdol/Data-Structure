#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node *prev, *next;
    Node(int data):data{data},prev{NULL},next{NULL}{}
};

void append(Node *&tail, int key)
{
    Node *newNode = new Node(key);
    tail->next = newNode;
    newNode->prev = tail;
    tail=newNode;
}

void printDoublyLinkedList(Node *root)
{
    while(root != NULL)
    {
        cout << root->data << " ";
        root = root->next;
    }
    cout << endl;
}

Node *reverseIteratively(Node *head)
{
    Node *tmp=head;
    tmp = tmp->next;
    swap(head->prev,head->next);

    while(tmp != NULL)
    {
        head = tmp;
        tmp=tmp->next;
        swap(head->prev,head->next);
    }
    return head;
}

Node *reverseRecursively(Node *head)
{
    if(head->next == NULL) return head;

    Node *root = reverseRecursively(head->next);

    Node *next = head->next;
    head->next = NULL;
    head->prev = next;
    next->prev = NULL;
    next->next=head;

    return root;
}

int main()
{
    Node *head = new Node(1);
    Node *tail = head;
    
    append(tail,2);
    append(tail,3);
    append(tail,4);
    append(tail,5);

    printDoublyLinkedList(head);

    // tail = head;
    // head = reverseIteratively(head);

    tail = head;
    head = reverseRecursively(head);

    printDoublyLinkedList(head);

    return 0;
}

