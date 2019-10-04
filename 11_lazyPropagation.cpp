///-------------------- Lazy Propagetion -------------------///

#include <bits/stdc++.h>

using namespace std;

#define MAX 1000

int arr[MAX];

struct Node
{
    int sum;
    int propaValue;
} tree[MAX*4];

void ini(int node, int start, int endd)
{
    if(start==endd)
    {
        tree[node].sum=arr[start];
        return;
    }
    int left=node*2;
    int right=left+1;
    int mid=(start+endd)/2;
    ini(left,start,mid);
    ini(right,mid+1,endd);
    tree[node].sum = tree[left].sum+tree[right].sum;
}

void update(int node, int start, int endd, int i, int j, int value)
{
    if(i>endd || j<start) return;
    if(i<=start && endd<=j)
    {
        tree[node].sum+=((endd-start+1)*value);
        tree[node].propaValue+=value;
        return;
    }
    int left=node*2;
    int right=left+1;
    int mid=(start+endd)/2;

    update(left,start,mid,i,j,value);
    update(right,mid+1,endd,i,j,value);

    tree[node].sum = tree[left].sum+tree[right].sum + ((endd-start+1)*tree[node].propaValue);
}

int query(int node, int start, int endd,int i, int j, int c=0)
{
    if(i>endd || j<start) return 0;
    if(i<=start && endd<=j)
    {
        return tree[node].sum + (c*(endd-start+1));
    }

    int left=node*2;
    int right=left+1;
    int mid=(start+endd)/2;

    int l = query(left,start,mid,i,j);
    int r = query(right,mid+1,endd,i,j);

    return l+r;
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

    ini(1,1,n);
    cout << "Array : ";
    for(int i=1;i<=n;i++) cout << arr[i] << " ";
    cout << endl << endl;
    cout << "Sum of range 1 to 8 is " << query(1,1,n,1,8) << endl << endl;
    cout << "Sum of range 2 to 6 is " << query(1,1,n,2,6) << endl << endl;
    cout << "Sum of range 1 to 5 is " << query(1,1,n,1,5) << endl << endl;
    cout << "Update index value 4 to 6, increase 3" << endl << endl;
    update(1,1,n,4,6,3);
    cout << "Sum of range 1 to 8 is " << query(1,1,n,1,8) << endl << endl;
    cout << "Update index value 2 to 5, increase 2" << endl << endl;
    update(1,1,n,2,5,2);
    cout << "Sum of range 1 to 8 is " << query(1,1,n,1,8) << endl << endl;

    return 0;
}


