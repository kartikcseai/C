// INSERTION SORT 
// time complexity : O(n^2)

#include<iostream>
using namespace std;
void insertion_sort(int arr[], int n){
    for(int i=1;i<n;i++){
        int curr=arr[i];
        int prev=i-1;
        while(prev>=0 && arr[prev]>curr){
            arr[prev+1]=arr[prev];
            prev--;   
        }
        arr[prev+1]=curr; // placing the current element in its correct position.
    }
}

void print_array(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n=5;
    int arr[]={4,1,5,2,3};
    insertion_sort(arr, n);
    print_array(arr, n);
    return 0;
}
