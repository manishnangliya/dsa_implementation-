#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int>&heap, int curr,int size)
{
    int l= 2*curr+1;
    int r = 2*curr+2;
    while(l<size)
    {
        int smallest;
        if(r==size)
          smallest = l;
        else
        {
            if(heap[l]< heap[r])
              smallest= l;
            else
              smallest=r;
        }
        
        if(heap[smallest] < heap[curr])
        {
            swap(heap[smallest], heap[curr]);
            curr= smallest;
            l= 2*curr+1;
            r = 2*curr+2;
        }
        else
          break;

    }
    
}
void desc_heapsort(vector<int>&heap)
{
    int size=heap.size();
    for(int i=size/2 -1; i>=0;i--)
    {
        heapify(heap,i,size);
    }
    
    for(int i=size-1;i>=0;i--)
    {
        swap(heap[i],heap[0]);
        heapify(heap,0,i);
    }
}
int main() {
    vector<int>heap={6,4,3,7,2,3,9};
    desc_heapsort(heap);
    for(auto it: heap)
      cout<<it<<" ";
}