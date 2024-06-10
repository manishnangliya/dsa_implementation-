#include<iostream>
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n) {
    for(int i=0;i<n-1;i++) {
        int minElementIndex = i; 
        for(int j=i+1;j<n;j++) {
            if(arr[j]<arr[minElementIndex]) {
                minElementIndex = j;
            }
        }
        swap(&arr[i], &arr[minElementIndex]);
    }
}

void bubbleSort(int arr[], int n) {
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-i-1;j++) {
            if(arr[j]>arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void insertionSort(int arr[], int n) {
    for(int i=1;i<n;i++) {
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void merge(int arr[], int lo, int mid, int hi) {
    int n1 = mid-lo+1;
    int n2 = hi-mid;
    int a[n1], b[n2];
    int k = lo;
    for(int i=0;i<n1;i++) {
        a[i] = arr[k];
        k++;
    }
    for(int i=0;i<n2;i++) {
        b[i] = arr[k];
        k++;
    }
    int i = 0, j = 0;
    k = lo;
    while(i<n1 && j<n2) {
        if(a[i]<b[j]) {
            arr[k] = a[i];
            i++;
        }
        else {
            arr[k] = b[j];
            j++;
        }
        k++;
    }
    while(i<n1) {
        arr[k] = a[i];
        i++;
        k++;
    }
    while(j<n2) {
        arr[k] = b[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int lo, int hi) {
    if(lo>=hi) {
        return;
    }
    int mid = (lo+hi)/2;
    mergeSort(arr,lo,mid);
    mergeSort(arr,mid+1,hi);
    merge(arr,lo,mid,hi);
}

int partition(int arr[], int lo, int hi) {
    int pivot = arr[hi];
    int i = lo-1, j;
    for(j=lo;j<hi;j++) {
        if(arr[j]<pivot) {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[j]);
    return i+1;
}

void quickSort(int arr[], int lo, int hi) {
    if(lo>=hi) {
        return;
    }
    int pi = partition(arr,lo,hi);
    quickSort(arr,lo,pi-1);
    quickSort(arr,pi+1,hi);
}

int main() {
    int arr[5] = {5,4,3,2,1};
    selectionSort(arr,5);
    bubbleSort(arr,5);
    insertionSort(arr,5);
    mergeSort(arr,0,4);
    quickSort(arr,0,4);
    for(int i=0;i<5;i++) {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}
