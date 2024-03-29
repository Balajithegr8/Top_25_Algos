#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[],int n,int i){
    int largest=i;
    int l=2*i+1;                //left index child
    int r=2*i+2;                // right index child

    if(l<n && arr[l]>arr[largest]){
        largest=l;
    }
    if(r<n && arr[r]>arr[largest]){
        largest=r;
    }
    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}

void heap_sort(int arr[],int n){

    for(int i=n/2-1;i>=0;i--){   // non leaf nodes therefore n/2-1 where n is the total nodes for the complete binary tree.
        heapify(arr,n,i); 
    }

    for(int i=n-1;i>0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }

}

void showdata(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl;;
}

int main(){
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
    heap_sort(arr,n);
    cout<<"Sorted array is : ";
    showdata(arr, n);
    return 0;
}