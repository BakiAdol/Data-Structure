///--------------------------- Segment Tree --------------------------------///
///------------------------- Find minimum valu --------------------------------///

#include <bits/stdc++.h>

using namespace std;

#define MAX 1000

int arr[MAX];
int tree[MAX*3];

void initialize(int node, int s, int e)
{
    if(s==e)
    {
        tree[node]=arr[s];
        return;
    }
    int left=node*2;
    int right=left + 1;
    int mid=(s+e)/2;
    initialize(left,s,mid);
    initialize(right,mid+1,e);
    tree[left]>tree[right] ? tree[node]=tree[right] : tree[node]=tree[left];
}
int query(int node, int s, int e, int i, int j)
{
    if(i>e || j<s) return 10000000;
    if(s>=i && e<=j) return tree[node];
    int left=node*2;
    int right=left+1;
    int mid=(s+e)/2;
    int nodeL = query(left,s,mid,i,j);
    int nodeR = query(right,mid+1,e,i,j);
    return (nodeL > nodeR ? nodeR : nodeL);
}


int main()
{
    int n=8;
    arr[1]=5;
    arr[2]=2;
    arr[3]=7;
    arr[4]=3;
    arr[5]=4;
    arr[6]=8;
    arr[7]=1;
    arr[8]=6;
    initialize(1,1,n);
    cout << "Tree : ";
    for(int i=1;i<=n;i++) cout << arr[i] << " ";
    cout << endl << endl;

    cout << "Segment Tree : ";
    for(int i=1;tree[i]!='\0';i++) cout << tree[i] << " ";
    cout << endl << endl;

    cout << "Minimum value of rnge 1 to 8 = "<< query(1,1,n,1,8) << endl;
    cout << "Minimum value of rnge 4 to 5 = "<< query(1,1,n,4,5) << endl;
    cout << "Minimum value of rnge 3 to 7 = "<< query(1,1,n,3,7) << endl;

    return 0;
}

