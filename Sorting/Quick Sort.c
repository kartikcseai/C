// QUICK SORT 
// time complexity : O(n^2)

#include<iostream>
#include<vector>
using namespace std;

int vpartition(vector<int> arr, int st, int end){
    int idx=st-1; 
    int pivotidx=arr[end];
    for(int j=0; j<end; j++){
       if(arr[j]<=pivotidx){
            idx++;
            swap(arr[j],arr[idx]);
       }
       idx++;
       swap(arr[end], arr[idx]);
    }
    return idx;
}
void quick_sort(vector<int> arr, int st, int end){
    if(st<end){
        int pivotidx=vpartition(arr, st, end);
        quick_sort(arr, st, pivotidx-1); // left half
        quick_sort(arr, pivotidx+1, end); // right half
    }
}
int main(){
    vector<int> arr={12,31,35,8,32,17};
    quick_sort(arr, 0, arr.size()-1);
    for(int val:arr){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}
