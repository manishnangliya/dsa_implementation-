//maxheap
#include <bits/stdc++.h>
using namespace std;
#define maxsize 1001
int size;
int heap[maxsize];


void init()
{
    size=0;
}
void push(int val)
{
    if(size>=maxsize)
     {
         cout<<"overflow condition\n";
         return;
     }
     heap[size]=val;
     int curr=size;
     while(curr>0 && heap[(curr-1)/2] < heap[curr])
     {
         swap( heap[(curr-1)/2] , heap[curr] );
         curr = (curr-1)/2;
     }
     size++;
}
void heapify(int curr)
{
    //Recursion
    
    // int largest = curr;
    // int l= 2* curr+1;
    // int r= 2* curr+2;
    // if(l<size && heap[l] > heap[largest])
    //     largest=l;
    // if(r< size && heap[r] > heap[largest])
    //   largest =r;
    // if(curr!= largest)
    // {
    //     swap(heap[curr] , heap[largest]);
    //     heapify(largest);
    // }
    
    //iterative

    while(2*curr +1< size)
    {
        int largest=curr;;
        int l=2*curr+1;
        int r= 2*curr+2;
        if(l<size && heap[l] > heap[largest])
          largest=l;
        if( r<size && heap[r]> heap[largest])
          largest =r;
        
        if(heap[curr] < heap[largest])
        {
            swap(heap[curr], heap[largest]);
            curr=largest;
        }
        else
            break;
    }


}
int pop()
{
    if(size<=0)
    {
        cout<<"underflow condition\n";
        return -1;
    }
    
    int popped = heap[0];
    heap[0]= heap[size-1];
    size--;
    heapify(0);
    return popped;
}
int top()
{
    if(size<=0)
    {
        cout<<" underflow\n";
        return -1;
    }
    return heap[0];
}
int main() 
{
    init();
    while(1)
    {
        cout<<"1:Push...2:Pop...3:show top...4:Terminate\n";
        int option;
        int element;
        cin>>option;
        switch(option)
        {
            case 1:
                cout<<"Enter element\n";
                cin>>element;
                push(element);
                break;
            case 2:
                cout<<"Popped "<<pop()<<"\n";
                break;
            case 3:
                cout<<"Top element "<<top()<<"\n";
                break;
            default:
                return 0;
        }
    }
}