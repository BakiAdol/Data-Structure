#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node *link;
};

class circularLinkedList{
    private:
        Node* head;
        Node* tail;
    public:
        circularLinkedList();
        void append(int value);
        void preappend(int value);
        void insertAnyPosition(int position, int value);
        void deleteAnyPosition(int position);
        void all();
};

circularLinkedList::circularLinkedList(){
    head=NULL;
}

void circularLinkedList::append(int value){
    Node* newNode = new Node;
    newNode->data=value;
    if(head==NULL){
        head=newNode;
        newNode->link=head;
        tail=newNode;
    }else{
        tail->link=newNode;
        newNode->link=head;
        tail=newNode;
    }
}

void circularLinkedList::preappend(int value){
    Node* newNode = new Node;
    newNode->data=value;
    if(head==NULL){
        head=newNode;
        newNode->link=head;
        tail=newNode;
    }else{
        tail->link=newNode;
        newNode->link=head;
        head=newNode;
    }
}

void circularLinkedList::insertAnyPosition(int position, int value){
    Node* newNode = new Node;
    newNode->data=value;
    if(position==1) preappend(value);
    else{
        Node* temp=head;
        position--;
        while(--position && temp->link->link!=head) temp=temp->link;
        if(temp->link->link==head) append(value);
        else{
            newNode->link=temp->link;
            temp->link=newNode;
        }
    }
}

void circularLinkedList::deleteAnyPosition(int position){
    if(position==1){
        head=head->link;
        tail->link=head;
    }else{
        Node* temp;
        while(--position && temp->link->link!=head) temp=temp->link;
        if(temp->link->link==head){
            temp->link=head;
            tail=temp;
        }else{
            temp->link=temp->link->link;
        }
    }
}

void circularLinkedList::all(){
    Node *temp=head;
    if(temp!=NULL){
        do{
            cout << temp->data << " ";
            temp=temp->link;
        }while(temp!=head);
    }
    cout << endl;
}

int main(){
    int n,value,pos;
    circularLinkedList ll;
    while(true){
        cout << "Instruction:" << endl;
        cout << "1.Append, 2.Preappend, 3.Insert any position, 4.Delete, 5.All, 0.Exit" << endl;
        cout << "Enter code : ";
        cin >> n;
        switch(n){
            case 1:
                cout << "Enter number you want to append in link list : ";
                cin >> value;
                ll.append(value);
                break;
            case 2:
                cout << "Enter number you want to preappend in link list : ";
                cin >> value;
                ll.preappend(value);
                break;
            case 3:
                cout << "Enter position and number you want to append in link list : ";
                cin >> pos >> value;
                ll.insertAnyPosition(pos,value);
                break;
            case 4:
                cout << "Enter position want to delete from list : ";
                cin >> pos;
                ll.deleteAnyPosition(pos);
                break;
            case 5:
                ll.all();
                break;
            case 0:
                return 0;
            default:
                cout << "Invalid code!" << endl;
        }
    }

    return 0;
}
