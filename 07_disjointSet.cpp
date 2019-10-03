#include <bits/stdc++.h>

using namespace std;

#define MAX 100

int parent[MAX];
int rankOfParent[MAX];

void makeSet(int n)
{
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
        rankOfParent[i]=0;
    }
}

int findParent(int s)
{
    if(s!=parent[s]) return parent[s]=findParent(parent[s]);
    else return s;
}

void unionSet(int a, int b)
{
    int parentOfa=findParent(a);
    int parentOfb=findParent(b);
    if(parentOfa==parentOfb) return;
    if(rankOfParent[parentOfa] < rankOfParent[parentOfb])
    {
        parent[parentOfa]=parentOfb;
    }
    else if(rankOfParent[parentOfa] > rankOfParent[parentOfb])
    {
        parent[parentOfb]=parentOfa;
    }
    else
    {
        parent[parentOfb]=parentOfa;
        rankOfParent[parentOfa]++;
    }
}

void showSet(int n)
{
    for(int i=0;i<n;i++)
    {
        cout << "Node = " << i << " , Parent = " << parent[i] << " and Rank = " << rankOfParent[i] << endl;
    }
}

int main()
{
    cout << "Enter number of set : ";
    int n;
    cin >> n;
    makeSet(n);
    unionSet(2,1);
    unionSet(4,0);
    unionSet(4,2);
    unionSet(3,1);

    showSet(n);
    return 0;
}


