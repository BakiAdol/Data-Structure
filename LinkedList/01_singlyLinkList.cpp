#include<bits/stdc++.h>

using namespace std;

struct Node{ ///like data type
    int data;
    Node *link;
};
class singlyLinkList{ ///singlyl link list class
    private:
        Node *head, *tail;
    public:
        singlyLinkList();
        void append(int value);
        void preappend(int value);
        void insertAnyPosition(int position, int value);
        void deleteAnyPosition(int position);
        void all();
};
singlyLinkList::singlyLinkList(){ /// constructor
    head=NULL;
}
void singlyLinkList::append(int value){ /// add value in end of this link list
    Node *newNode=new Node;
    newNode->data=value;
    newNode->link=NULL;
    if(head==NULL){
        head=newNode;
        tail=newNode;
    }else{
        tail->link=newNode;
        tail=newNode;
    }
}
void singlyLinkList::preappend(int value){ ///add value very begining of this link list
    Node *newNode=new Node;
    newNode->data=value;
    newNode->link=NULL;
    if(head==NULL){  ///if this link list hase no value
        head=newNode;
        tail=newNode;
    }else{
        newNode->link=head;
        head=newNode;
    }
}
void singlyLinkList::insertAnyPosition(int position, int value){ /// insert item in any positon
    Node *temp=head;
    Node *newNode=new Node;
    newNode->data=value;
    if(head==NULL){
        head=newNode;
        tail=newNode;
    }else{
        if(position==1){
            newNode->link=head;
            head=newNode;
        }else{
            position--;
            while(--position){
                temp=temp->link;
                if(temp==NULL) break;
            }
            if(temp==NULL){
                tail->link=newNode;
                tail=newNode;
            }else{
                newNode->link=temp->link;
                temp->link=newNode;
            }
        }
    }
}
void singlyLinkList::deleteAnyPosition(int position){ ///delete element of any osition
    if(position==1) head=head->link;
    else{
        Node *temp=head,*del;
        position--;
        while(--position) temp=temp->link;
        del=temp->link;
        if(del==NULL){
            temp->link=NULL;
            tail=temp;
        }else{
            temp->link=del->link;
        }
    }
}
void singlyLinkList::all(){ /// print link list's all value
    Node *print=head;
    while(print!=NULL){
        cout << print->data << " ";
        print=print->link;
    }
    cout << endl;
}
int main(){
    int n,value,pos;
    singlyLinkList ll;
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
