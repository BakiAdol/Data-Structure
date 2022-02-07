#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct Node{
    T data;
    Node *next;
    Node(T data):data{data},next{NULL}{}
};

template <typename T>
class Queue{
    Node<T> *front, *rear;
    
    public:
    Queue():front{NULL},rear{NULL}{}

    bool isEmpty()
    {
        return front == NULL;
    }

    void enqueue(T var)
    {
        if(front == NULL)
        {
            front = new Node<T>(var);
            rear = front;
        }
        else
        {
            rear->next = new Node<T>(var);
            rear = rear->next;
        }
    }
    
    void dequeue(){
        if(front != NULL)
        {
            Node<T> *tmp=front;
            front=front->next;
            delete tmp;
        }
    }

    T frontElement()
    {
        if(front == NULL) throw "Queue is empty!";
        return front->data;
    }

    int size()
    {
        Node<T> *tmp =front;
        int s=0;
        while(tmp!=NULL)
        {
            s++;
            tmp = tmp->next;
        }
        return s;
    }
};


int main(){

    Queue <int>q;

    cout <<"Is empty : "<< q.isEmpty() << endl;
    cout <<"Size : "<< q.size() << endl;

    q.enqueue(5);
    q.enqueue(3);

    cout <<"Size : "<< q.size() << endl;

    q.enqueue(9);
    q.enqueue(2);

    cout <<"Is empty : "<< q.isEmpty() << endl;
    cout <<"Size : "<< q.size() << endl;

    while(!q.isEmpty())
    {
        cout << "Front " << q.frontElement() << endl;
        q.dequeue();
    }
    return 0;
}

