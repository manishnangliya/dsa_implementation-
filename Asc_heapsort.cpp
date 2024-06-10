#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int>&heap, int curr,int size) //top to dowm
{
    int largest= curr;
    int l= 2*curr +1;
    int r= 2*curr+2;
    
    if(l<size && heap[l] > heap[largest])
        largest= l;
    if(r< size && heap[r] > heap[largest])
        largest = r;
    if(curr!= largest) //stoping condition either we reach leave and parent >child ( holding property of max heap)
    {
        swap(heap[largest],heap[curr]);
        curr = largest;
        heapify(heap,curr,size);
    }
}
void heapsort(vector<int>&heap)
{
    int size= heap.size();
    for(int i=size/2 -1; i>=0;i--)
    {
        heapify(heap,i,size);
    }
    
    for(int i= size-1;i>=0;i--)
    {
        swap(heap[0],heap[i]);
        heapify(heap,0,i);
    }
    
}
int main()
{
    vector<int>heap={ 9,5,4,5,3,2};
    heapsort(heap);
    
    for(auto it:heap)
      cout<<it<<" ";
}