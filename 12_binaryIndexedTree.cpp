#include <bits/stdc++.h>

using namespace std;

#define MAX 100009

int arr[MAX];
int tree[MAX];

int query(int i)
{
    int sum=0;
    while(i>0)
    {
        sum+=tree[i];
        i-=(i & -i);
    }
    return sum;
}

void update(int i, int value, int n)
{
    while(i<=n)
    {
        tree[i]+=value;
        i += (i & -i);
    }
}

int spacificIndexValue(int indx)
{
    int sum=tree[indx];
    if(indx>1)
    {
        int previous=indx-(indx & -indx);
        indx--;
        while(previous!=indx)
        {
            sum-=tree[indx];
            indx-=(indx & -indx);
        }
    }
    return sum;
}

int main()
{
    int n=10,a;
    for(int i=1;i<=n;i++)
    {
        arr[i]=i;
        update(i,arr[i],n);
    }
    cout << "Sum of index 1 to 10 = " << query(10) << endl;
    cout << "Sum of index 1 to 5 = " << query(5) << endl;
    cout << "Update index 3 to value 10" << endl;
    update(3,10,n); /// add value 10 to index 3
    cout << "Sum of index 1 to 5 = " << query(5) << endl;
    cout << "Index value of 6 is " << spacificIndexValue(6) << endl;
    return 0;
}
