#include <bits/stdc++.h>
using namespace std;

void getdata(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<"Enter "<<i+1<<" element :"; 
        cin>>arr[i];
    }
    
}

void showdata(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<"The "<<i+1<<" element is :"; 
        cout<<arr[i]<<endl;
    }
}

bool linear_search(int arr[],int n,int val){
    for(int i=0;i<n;i++){
        if(arr[i]==val){return true;}
    }
    return false;
}

int main(){
    int n;
    cout<<"Enter the number of elements :";
    cin>>n;
    int arr[n];
    getdata(arr,n);
    cout<<"Enter the number to be searched :";
    int key;
    cin>>key;
    if(linear_search(arr,n,key)){cout<<"Found ";}
    else{cout<<"Not found";}
    return 0;
}