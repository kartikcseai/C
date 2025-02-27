// BUBBLE SORT 
// time complexity : O(n^2)

#include<iostream>
using namespace std;
void bubble_sort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        bool is_swap=false;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                is_swap=true;
            }
        }
        if(!is_swap) return;    // array is already sorted
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
    bubble_sort(arr, n);
    print_array(arr, n);
    return 0;
}
