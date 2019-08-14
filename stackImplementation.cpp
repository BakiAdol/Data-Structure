/*
  Implement stakc using array
*/
#include<bits/stdc++.h>

using namespace std;

class Stack{
    private:
        int top;
        int stackk[10];

    public:
        Stack(){   ///Default constructor
            top=-1;
        }
        bool isEmpty(){ ///Check whatever stack empty or not
            return (top==-1 ? true : false);
        }
        bool isFull(){  ///Check whatever stack full or not
            return (top==10 ? true : false);
        }
        void push(int value){  ///Push item in stack
            if(isFull()) cout << "Stack Overflow!" << endl;
            else stackk[++top] = value;
        }
        int pop(){  ///Pop item from stack
            if(isEmpty()){
                cout << "Stack Underflow!" << endl;
                return INT_MAX;
            }
            else return stackk[top--];
        }
        int numberOFItem(){ ///Count number of item in stack
            return top+1;
        }
        int peek(int position){  ///Peek item from stack
            position--;
            if(isEmpty()){
                cout << "Stack Underflow!" << endl;
                return INT_MAX;
            }else if(top<position){
                cout << "There are no element is position " << position << endl;
                return INT_MAX;
            }else return stackk[position];
        }
        void change(int position, int value){  ///Change stack value
            position--;
            if(isEmpty()) cout << "Stack Underflow!" << endl;
            else if(top<position) cout << "There are no element is position " << position << endl;
            else stackk[position]=value;
        }
        void all(){  ///Display stack's all item
            for(int i=top;i>=0;i--) cout << stackk[i] << " ";
            cout << endl;
        }
};

int main(){
    cout << "Isntructions:" << endl;
    cout << "1.Push, 2.Pop, 3.Peek, 4.Change, 5.NumberOfItem, 6.Empty, 7.Full, 8.All, 9.Exit" << endl;
    int pos,value;
    cout << "Enter code : ";
    Stack s;
    while(cin >> pos){
        switch(pos){
            case 1:
                cout << "Enter the number you want to push : ";
                int value;
                cin >> value;
                s.push(value);
                break;
            case 2:
                value=s.pop();
                cout << "Pop item is " << value << endl;
                break;
            case 3:
                cout << "Enter position number : ";
                cin >> pos;
                value=s.peek(pos);
                cout << "Peek item is " << value << endl;
                break;
            case 4:
                cout << "Enter position number and value : ";
                cin >> pos >> value;
                s.change(pos,value);
                break;
            case 5:
                cout << s.numberOFItem() << " item is in stack." << endl;
                break;
            case 6:
                cout << (s.isEmpty() ? "Stack is empty\n" : "Stack is not empty\n");
                break;
            case 7:
                cout << (s.isFull() ? "Stack is full\n" : "Stack is not full\n");
                break;
            case 8:
                s.all();
                break;
            case 9:
                return 0;
            default:
                cout << "Invalid Code!" << endl;
                break;
        }
        cout << "Enter code again : ";
    }
    return 0;
}
