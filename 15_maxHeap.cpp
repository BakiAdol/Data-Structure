#include <bits/stdc++.h>

using namespace std;

class MaxHeap{
    private:
        int size=0;
        vector<int> v={0};
        int parent(int pos){return pos>>1;}
        int leftChild(int pos){return pos<<1;}
        int rightChild(int pos){return (pos<<1)+1;}
        
    public:
        bool isEmpty(){return size==0;}
        void insert(int val);
        void shiftUp(int pos);
        void shiftDown(int pos);
        int extractMax();
};

void MaxHeap::shiftUp(int pos)
{
    if(pos==1 or v[pos] <= v[parent(pos)]) return;
    swap(v[pos],v[parent(pos)]);
    shiftUp(parent(pos));
}

void MaxHeap::shiftDown(int pos)
{
    if(leftChild(pos)>size) return;
    int p = leftChild(pos);
    if(rightChild(pos)<=size and v[rightChild(pos)]>v[leftChild(pos)])
    {
        p=rightChild(pos);
    }
    if(v[pos]>=v[p]) return;
    swap(v[pos],v[p]);
    shiftDown(p);
}

void MaxHeap::insert(int val)
{
    v.push_back(val);
    size++;
    shiftUp(size);
}

int MaxHeap::extractMax()
{
    int maxNumber=v[1];
    v[1]=v[size];
    v.pop_back();
    size--;
    shiftDown(1);
    return maxNumber;
}

int main()
{
    MaxHeap* pq = new MaxHeap();
    pq->insert(5);
    pq->insert(4);
    pq->insert(6);
    pq->insert(2);

    cout << pq->extractMax() << endl;
    cout << pq->extractMax() << endl;

    return 0;
}
