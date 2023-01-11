#include <iostream>
using namespace std;

int partition(int arr[], int i, int j){
    int val=arr[i];
    int h=i;
    int k;
    for(k=i+1;k<j;k++){
        if(arr[k]<val){
            h=h+1;
            swap(arr[h],arr[k]);
        }
    }
    swap(arr[i],arr[h]);
    return h;
}

int* quicksort(int arr[], int l, int r){
    
    if(l<r){
        int pi=partition(arr,l,r);
        quicksort(arr,l,pi-1);
        quicksort(arr,pi+1,r);
    }
    return arr;
}

void pa(int A[], int size){
    for (auto i = 0; i < size; i++)
        cout << A[i] << " ";
}

int main(){
    int arr[] = { 1, 4, 1, 2, 7, 5, 2 };
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout<<"Sorted array is : ";
    pa(quicksort(arr,0,n), n);
    return 0;
}