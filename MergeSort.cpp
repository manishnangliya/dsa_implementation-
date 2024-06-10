#include <bits/stdc++.h>

using namespace std;

void merge(int arr[], int lb , int mid,int ub)
{
    int newarr[ub-lb+1];
    
    int i=lb, j=mid+1,k=0;
    while(i<=mid && j<=ub)
    {
        if(arr[i]<arr[j])
        {
            newarr[k]=arr[i];
            i++;
            k++;
        }
        else
        {
            newarr[k]= arr[j];
            j++;
            k++;
        }
    }
    while(i<=mid)
    {
        newarr[k]=arr[i];
        i++;
        k++;
    }
    while(j<=ub)
    {
        newarr[k]=arr[j];
        j++;
        k++;
    }
    
    k=0;
    for(i=lb ;i<=ub;i++)
    {
        arr[i]=newarr[k++];
    }
}

void mergeSort(int arr[], int lb , int ub)
{
    if(lb<ub)
    {
        int mid = lb +(ub-lb)/2;
        mergeSort(arr,lb,mid);
        mergeSort(arr,mid+1,ub);
        
        merge(arr,lb,mid,ub);  // first arr--> lb to mid    second arr ---> mid+1 to up
    }
    
}
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++)
      cout<<arr[i]<<" ";
}
