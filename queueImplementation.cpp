#include<bits/stdc++.h>

using namespace std;

class Queue{ ///Define queue
    private:
        int arr[5];
        int frontt,rear,countt,capacity;
    public:
        Queue();
        bool isEmpty();
        bool isFull();
        void enqueue(int value);
        void dequeue();
        int numberOfElement();
        int peek();
        void all();
};
Queue::Queue(){ ///Constructor
    frontt=0;
    rear=-1;
    countt=0;
    capacity=5;
}
bool Queue::isEmpty(){ /// check whatever queue empty or not
    return countt<1;
}
bool Queue::isFull(){  /// check whatever queue full or not
    return countt==capacity;
}
void Queue::enqueue(int value){ /// insert value in queue
    if(isFull()) cout << "OverFlow" << endl;
    else{
        arr[++rear]=value;
        countt++;
    }
}
void Queue::dequeue(){  /// delete value from queue
    if(isEmpty()) cout << "UnderFlow" << endl;
    else{
        countt--;
        for(int i=0;i<rear;i++) swap(arr[i],arr[i+1]);
        rear--;
    }
}
int Queue::peek(){  /// return first item from queue
    if(isEmpty()) cout << "UnderFlow" << endl;
    else{
        return arr[frontt];
    }
}
int Queue::numberOfElement(){  /// return total number of queue element
    return countt;
}
void Queue::all(){  /// print all queue element
    for(int i=frontt;i<=rear;i++) cout << arr[i] << " ";
    cout << endl;
}
/*
  Implement queue using array
*/

int main(){
    int n,value;
    Queue q;
    while(true){
        cout << "Instruction:" << endl;
        cout << "1.Enqueue, 2.Dequeue, 3.Peek, 4.Empty, 5.Full, 6.Number of Element, 7.All, 0.Exit" << endl;
        cout << "Enter code : ";
        cin >> n;
        switch(n){
            case 1:
                cout << "Enter number you want to enqueue : ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                cout << "Peek value : " << q.peek() << endl;
                break;
            case 4:
                cout << (q.isEmpty() ? "Empty\n" : "Not Empty\n");
                break;
            case 5:
                cout << (q.isFull() ? "Full\n" : "Not Full\n");
                break;
            case 6:
                cout << "Queue has " << q.numberOfElement() << " element" << endl;
                break;
            case 7:
                q.all();
                break;
            default:
                cout << "Invalid code!" << endl;
        }
    }
    return 0;
}
