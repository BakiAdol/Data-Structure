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
    update(3,10,n);
    cout << "Sum of index 1 to 5 = " << query(5) << endl;
    return 0;
}

