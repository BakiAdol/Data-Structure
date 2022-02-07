// min heap data structure using array

#include <bits/stdc++.h>

using namespace std;

class MinHeap{
    int *heapContainer;
    int capacity;
    int heapSize;
    public:
    MinHeap(int);
    int getHeapSize();
    int linearSearch(int);
    void printHeap();
    int height();
    int parent(int);
    void insert(int);
    int leftChild(int);
    int rightChild(int);
    void minHeapify(int);
    int extractMin();
    int getMin();
    void deleteKey(int);
};

MinHeap::MinHeap(int capacity):capacity{capacity},heapSize{0}
{
    heapContainer = new int[capacity];
}

int MinHeap::getHeapSize()
{
    return heapSize;
}

int MinHeap::parent(int child)
{
    return (child-1)/2;
}

int MinHeap::leftChild(int parent)
{
    return parent*2 +1;
}

int MinHeap::rightChild(int parent)
{
    return parent*2 +2;
}

int MinHeap::linearSearch(int key)
{
    for(int i=0;i<heapSize;i++)
    {
        if(heapContainer[i]==key) return i;
    }
    return heapSize;
}

void MinHeap::printHeap()
{
    for(int i=0;i<heapSize;i++)
    {
        cout << heapContainer[i] << " ";
    }
    cout << endl;
}

int MinHeap::height()
{
    return ceil(log2(heapSize+1))-1;
}

void MinHeap::insert(int key)
{
    if(heapSize == capacity)
    {
        cout << "Heap is Full!" << endl;
    }
    else
    {
        heapContainer[heapSize++]=key;
        int curentNode = heapSize-1;
        while(curentNode>0 and heapContainer[curentNode] < heapContainer[parent(curentNode)])
        {
            swap(heapContainer[curentNode],heapContainer[parent(curentNode)]);
            curentNode = parent(curentNode);
        }
    }
}

void MinHeap::minHeapify(int parent=0)
{
    int lChild = leftChild(parent);
    int rChild = rightChild(parent);
    int minNode = parent;

    if(lChild < heapSize and heapContainer[minNode]>heapContainer[lChild])
    {
        minNode = lChild;
    }
    if(rChild < heapSize and heapContainer[minNode] > heapContainer[rChild])
    {
        minNode = rChild;
    }

    if(minNode != parent)
    {
        swap(heapContainer[minNode],heapContainer[parent]);
        minHeapify(minNode);
    }
}

int MinHeap::extractMin()
{
    if(heapSize <= 0) return INT_MAX;
    if(heapSize == 1) return heapContainer[heapSize--];
    
    int minValue = heapContainer[0];
    heapContainer[0]=heapContainer[--heapSize];

    minHeapify();

    return minValue;
}

int MinHeap::getMin()
{
    return heapContainer[0];
}

void MinHeap::deleteKey(int key)
{
    int keyPos = linearSearch(key);
    if(keyPos==heapSize) return;

    // move INT_MIN to root of the min heap
    heapContainer[keyPos]=INT_MIN;
    while(keyPos != 0 and heapContainer[keyPos] < heapContainer[parent(keyPos)])
    {
        swap(heapContainer[keyPos],heapContainer[parent(keyPos)]);
        keyPos=parent(keyPos);
    }

    // now delete root that is bloody INT_MIN
    extractMin();
}

int main(){

    cout << "Enter heap size : ";
    int len,key,keyPos;
    cin >> len;
    MinHeap minheap(len);
    
    while(true)
    {
        for(int i=0;i<94;i++) cout << "-";
        cout << endl;
        cout << "1. Insert | 2. Search | 3. Delete | 4. GetMin | 5. ExtractMin | 6. Height | 7. Print | 0. Exit" << endl;
        for(int i=0;i<94;i++) cout << "-";
        cout << endl;

        int option;
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "Enter key : ";
            cin >> key;
            minheap.insert(key);
            break;
        case 2:
            cout << "Enter key : ";
            cin >> key;
            keyPos = minheap.linearSearch(key);
            cout << (keyPos==minheap.getHeapSize() ? "Not" : "") << " found!" << endl;
            break;
        case 3:
            cout << "Enter key : ";
            cin >> key;
            minheap.deleteKey(key);
            break;
        case 4:
            cout << "Minimum key is : " << minheap.getMin() << endl;
            break;
        case 5:
            cout << "Minimum key is : " << minheap.extractMin() << endl;
            break;
        case 6:
            cout << "Height of this heap is : " << minheap.height() << endl;
            break;
        case 7:
            minheap.printHeap();
            break;
        default:
            return 0;
        }
    }
    return 0;
}
