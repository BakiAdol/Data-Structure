#include<bits/stdc++.h>

using namespace std;

struct Node{ ///like data type
    int data;
    Node *previous;
    Node *next;
};

class doublyLinkedList{ ///doublyLinkedList link list class
    private:
        Node *head, *tail;
    public:
        doublyLinkedList();
        void append(int value);
        void preappend(int value);
        void insertAnyPosition(int position, int value);
        void deleteAnyPosition(int position);
        void update(int position, int value);
        void all();
};

doublyLinkedList::doublyLinkedList(){ /// constructor
    head=NULL;
}

void doublyLinkedList::append(int value){ /// add value in end of this link list
    Node *newNode=new Node;
    newNode->data=value;
    newNode->previous=NULL;
    newNode->next=NULL;
    if(head==NULL){
        head=newNode;
        tail=newNode;
    }else{
        tail->next=newNode;
        newNode->previous=tail;
        tail=newNode;
    }
}

void doublyLinkedList::preappend(int value){ ///add value very begining of this link list
    Node *newNode=new Node;
    newNode->data=value;
    newNode->previous=NULL;
    newNode->next=NULL;
    if(head==NULL){  ///if this link list hase no value
        head=newNode;
        tail=newNode;
    }else{
        newNode->next=head;
        head->previous=newNode;
        head=newNode;
    }
}

void doublyLinkedList::insertAnyPosition(int position, int value){ /// insert item in any positon
    Node *temp=head;
    Node *newNode=new Node;
    newNode->data=value;
    newNode->previous=NULL;
    newNode->next=NULL;
    if(head==NULL){
        head=newNode;
        tail=newNode;
    }else{
        if(position==1){
            newNode->next=head;
            head->previous=newNode;
            head=newNode;
        }else{
            position--;
            while(--position && temp->next!=NULL) temp=temp->next;
            if(temp->next==NULL){
                temp->next=newNode;
                newNode->previous=temp;
                tail=newNode;
            }else{
                temp->next->previous=newNode;
                newNode->next=temp->next;
                temp->next=newNode;
                newNode->previous=temp;
            }
        }
    }
}

void doublyLinkedList::deleteAnyPosition(int position){ ///delete element of any osition
    if(position==1){
        head=head->next;
        head->previous=NULL;
    }
    else{
        Node *temp=head;
        while(--position && temp->next!=NULL) temp=temp->next;
        if(temp->next==NULL){
            tail=temp->previous;
            tail->next=NULL;
            temp=NULL;
        }else{
            temp->previous->next=temp->next;
            temp->next->previous=temp->previous;
        }
    }
}

void doublyLinkedList::all(){ /// print link list's all value
    Node *print=head;
    while(print!=NULL){
        cout << print->data << " ";
        print=print->next;
    }
    cout << endl;
    print=tail;
    while(print!=NULL){
        cout << print->data << " ";
        print=print->previous;
    }
    cout << endl;
}

int main(){
    int n,value,pos;
    doublyLinkedList ll;
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
