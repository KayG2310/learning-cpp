#include <bits/stdc++.h>
using namespace std;
int pivot(vector<int>arr, int low, int high){
    int pivotele = arr[low];
    // by default our array is the first element
    int i = low;
    int j = high;
    while(i<j){
        while(arr[i]<= pivotele && i<=high-1){
            i++;
        }
        while(arr[j]>= pivotele && j>=low+1){
            j--;
        }
        if(i<j) swap(arr[i], arr[j]);
    }
    swap(arr[j] arr[low]);
    return j;
}

void qs(vector<int>arr, int low, int high){
    if(low<high){
        int pivot = pivot(arr, low, high);
        qs(arr, low, pivot-1);
        qs(arr, pivot+1, high);
        
    }
}

vector<int> quicksort(vector<int> arr){
    qs(arr, 0, arr.size()-1);
    
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n;i++){
        cin>>arr[i];
    }
    int i=0;
    int j = n-1;
    
}
