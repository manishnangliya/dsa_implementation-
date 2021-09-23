#include <bits/stdc++.h>

using namespace std;

//int partition(int arr[], int lb , int ub)
// {
//     int pivot = arr[lb];
//     int start =lb,end=ub;
//     while(start<end)
//     {
//         while(arr[start]<=pivot)
//           start++;
//         while(arr[end] > pivot)
//           end--;
//         if(start< end)
//         {
//             swap(arr[start],arr[end]);
//         }
//     }
//     swap(arr[end], arr[lb]);
//     return end;
// }
int partition (int a[], int l, int r) {
    int pivot = a[r];
    int i = l;
    for (int j = l; j < r; j++) {
        if (a[j] < pivot) 
            swap (a[i++], a[j]);
    }
    swap (a[i], a[r]);
    return i;
}
void QuickSort(int arr[], int lb,int ub)
{
    if(lb< ub)
    {
        int loc = partition(arr, lb, ub);
        QuickSort(arr,lb,loc-1);
        QuickSort(arr,loc+1, ub);
    }
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    QuickSort(arr,0,n-1);
    for(int i=0;i<n;i++)
      cout<<arr[i]<<" ";
}
