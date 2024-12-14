#include<iostream>
using namespace std;
void heapify(int *arr, int n, int i){
        int largest = i;
        int left = 2*i;
        int right = 2*i +1;
        if(left <=n && arr[left]>arr[largest]){
            largest = left;
        }
        if(right<=n && arr[right]>arr[largest]){
            largest = right;
        }
        if(largest != i){
            // meaning it has been changed
            int temp = arr[largest];
            arr[largest] = arr[i];
            arr[i] = temp;
            heapify(arr, n, largest);
        }
}
void heap_sort(int *arr, int n){
    int size = n;
    while(size>1){
        int temp = arr[1];
        arr[1] = arr[size];
        arr[size] = temp;
        size--;
        heapify(arr,size, 1);
        
    }
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n+1];
        arr[0] = -1;
        // we will use 1- base indexing
        for(int i=1; i<=n; i++){
            cin>>arr[i];
        }
        for(int i=n/2; i>0; i--){
            heapify(arr,n,i);
        }

        heap_sort(arr,n);
        for(int i=1; i<=n; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}
