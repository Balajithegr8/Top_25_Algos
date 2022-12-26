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

bool binary_search(int arr[],int high,int val,int low){
    
    int mid=(low+high)/2;
    
    if(arr[mid]==val){
        return true;
    }

    if(arr[mid]>val){
        return binary_search(arr,mid-1,val,low);
    }

    if(arr[mid]<val){
        return binary_search(arr,high,val,mid+1);
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
    if(binary_search(arr,n,key,0)){cout<<"Found ";}
    else{cout<<"Not found";}
    return 0;
}