///--------------------------- Segment Tree --------------------------------///
/// -----------find sum of  some index inside range

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
    tree[node]=tree[left]+tree[right];
}
int query(int node, int s, int e, int i, int j)
{
    if(i>e || j<s) return 0;
    if(s>=i && e<=j) return tree[node];
    int left=node*2;
    int right=left+1;
    int mid=(s+e)/2;
    int nodeL = query(left,s,mid,i,j);
    int nodeR = query(right,mid+1,e,i,j);
    return nodeL+nodeR;
}

void update(int node, int s, int e, int indx, int value)
{
    if(s>indx || indx>e) return;
    if(s>=indx && indx>=e)
    {
        tree[node]=value;
        return;
    }
    int left=node*2;
    int right=left+1;
    int mid=(s+e)/2;
    update(left,s,mid,indx,value);
    update(right,mid+1,e,indx,value);
    tree[node]=tree[left]+tree[right];
}

int minimun(int node, int s, int e, int i, int j)
{
    
}


int main()
{
    int n=8;
    for(int i=1;i<=n;i++) arr[i]=i;
    // 1, 2, 3, 4, 5, 6, 7, 8
    initialize(1,1,n);
    cout << "Current Segment Tree : ";
    for(int i=1;tree[i]!='\0';i++) cout << tree[i] << " ";
    cout << endl << endl;

    cout << "Sum of 1 to 5 = " << query(1,1,n,1,5) << endl << endl;
    cout << "Update value of index 3 to value 6" << endl << endl;
    update(1,1,n,3,6);

    cout << "Current Segment Tree : ";
    for(int i=1;tree[i]!='\0';i++) cout << tree[i] << " ";
    cout << endl << endl;

    cout << "Sum of 1 to 5 = " << query(1,1,n,1,5) << endl << endl;

    return 0;
}
