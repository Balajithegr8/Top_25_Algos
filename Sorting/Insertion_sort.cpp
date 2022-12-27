#include <bits/stdc++.h>
using namespace std;

void getdata(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<"Enter "<<i+1<<" element :"; 
        cin>>arr[i];
    }
    
}

void showdata(int arr[],int n){
    cout<<"The array is : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl;;
}

void insertion_sort(int arr[],int n){
    int i,j,key;
    for(i=1;i<n;i++){
        key=arr[i];
        j=i-1;

        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}

int main(){
    int n;
    cout<<"Enter the number of elements :";
    cin>>n;
    int arr[n];
    getdata(arr,n);
    cout<<endl;
    cout<<"Data before sorting"<<endl;
    showdata(arr,n);
    insertion_sort(arr,n);
    cout<<"Data after sorting"<<endl;
    showdata(arr,n);

    
    return 0;
}