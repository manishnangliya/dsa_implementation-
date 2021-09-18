#include <bits/stdc++.h>

using namespace std;

void InsertionSort(int arr[], int n)
{
    for(int i=1;i<n;i++)
    {
        int ele = arr[i],j=i-1;
        while(j>=0 && arr[j]>ele)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=ele;
    }
}
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    InsertionSort(arr,n);
    for(int i=0;i<n;i++)
      cout<<arr[i]<<" ";
}
