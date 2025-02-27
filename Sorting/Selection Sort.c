// SELECTION SORT
// time complexity : O(n^2)

#include<iostream>
using namespace std;
void selection_sort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        int smallest_idx=i;    // unsorted part starting 
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[smallest_idx]){
                smallest_idx=j;
            }
        }
        swap(arr[i],arr[smallest_idx]);
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
    selection_sort(arr, n);
    print_array(arr, n);
    return 0;
}
