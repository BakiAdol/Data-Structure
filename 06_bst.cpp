#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int n)
    {
        data=n;
        left=NULL;
        right=NULL;
    }
};


void insertNode(Node* root, int num)
{
    if(num<root->data)
    {
        if(root->left==NULL) root->left=new Node(num);
        else insertNode(root->left,num);
    }
    else
    {
        if(root->right==NULL) root->right=new Node(num);
        else insertNode(root->right,num);
    }
}


void inorderPrint(Node* root)
{
    if(root!=NULL)
    {
        inorderPrint(root->left);
        cout << root->data << " ";
        inorderPrint(root->right);
    }
}
void preorderPrint(Node* root)
{
    if(root!=NULL)
    {
        cout << root->data << " ";
        preorderPrint(root->left);
        preorderPrint(root->right);
    }
}

void postorderPrint(Node* root)
{
    if(root!=NULL)
    {
        postorderPrint(root->left);
        postorderPrint(root->right);
        cout << root->data << " ";
    }
}

Node* minValue(Node* root)
{
    if(root==NULL) return 0;
    while(root->left!=NULL) root=root->left;
    return root;
}

Node* maxValue(Node* root)
{
    if(root==NULL) return 0;
    while(root->right!=NULL) root=root->right;
    return root;
}

Node* deleteNode(Node* root, int num)
{
    if(root==NULL) return root;
    if(num < root->data)
    {
        root->left = deleteNode(root->left,num);
    }
    else if(num > root->data)
    {
        root->right = deleteNode(root->right,num);
    }
    else
    {
        if(root->left == NULL)
        {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = minValue(root->right);
        root->data = temp->data;
        root->right =deleteNode(root->right,temp->data);
    }
    return root;
}


int main()
{
    int num;
    Node* root=NULL;
    Node* mn;
    int code;
    cout << "1. Insert 2. Inorder, 3. Preorder, 4. Postorder, 5. Delete, 6.Minimuv, 7. Maximum" << endl;
    cout << "Enter Code : ";
    while(cin >> code && code)
    {
        switch(code)
        {
            case 1:
                cout << "Enter number you want to start : ";
                cin >> num;
                if(root==NULL) root=new Node(num);
                else insertNode(root,num);
                break;
            case 2:
                cout << "Inorder : ";
                inorderPrint(root);
                cout << endl;
                break;
            case 3:
                cout << "Preorder : ";
                preorderPrint(root);
                cout << endl;
                break;
            case 4:
                cout << "Postorder : ";
                postorderPrint(root);
                cout << endl;
                break;
            case 5:
                cout << "Enter number want to delete : ";
                cin >> num;
                root=deleteNode(root,num);
                break;
            case 6:
                mn=minValue(root);
                cout << "Minimum value : " << mn->data << endl;
                break;
            case 7:
                mn=maxValue(root);
                cout << "Maximum value : " << mn->data << endl;
                break;
            default:
                cout << "Invalid Code!" << endl;
        }
    }
    return 0;
}

