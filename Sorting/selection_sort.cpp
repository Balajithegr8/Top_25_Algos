#include <bits/stdc++.h>  //fastest time complexity O(n)
using namespace std;


void selection_sort(int arr[],int n){
    int i,j,min;

    for(i=0;i<n-1;i++){
        min=i;

        for(j=i+1; j<n ;j++){   
            
            if(arr[j]<arr[min]){
                min=j;
            }
        }

        if(min!=i){
            swap(arr[min],arr[i]);
        }
        
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
    selection_sort(arr,n);
    cout<<"Sorted array is : ";
    showdata(arr, n);
    return 0;
}