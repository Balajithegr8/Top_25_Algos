#include <iostream>
using namespace std;

int* countingsort(int arr[],int n){
    int k=arr[0];
    for(int i=0;i<n;i++){
        k=max(k,arr[i]);
    }

    int count[10]={0};
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }

    for(int i=1;i<=k;i++){
        count[i]+=count[i-1];
    }

    int output[n];
    for(int i=n-1;i>=0;i--){
        output[--count[arr[i]]]=arr[i];
    }
    
    for(int i=0;i<n;i++){
        arr[i]=output[i];
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
    pa(countingsort(arr,n), n);
    return 0;
}