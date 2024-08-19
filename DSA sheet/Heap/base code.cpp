#include<iostream>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;
    
    heap(){
        arr[0] = -1;
        size = 0;
        
    }
    
    void insert(int value){
        size +=1;
        int index = size;
        arr[index] = value;
        
        while(index>1){
            int parent = index/2;
            if(arr[parent]< arr[index]){
                int temp = arr[parent];
                arr[parent] = arr[index];
                arr[index] = temp;
                index = parent;
            }
            else{
                return;
            }
        }
    }
    void deletion(){
        if(size==0){
            cout<<"nothing to delete"<<endl;
            return;
        }
        arr[1] = arr[size];
        size--;
        
        int i=1;
        while(i<size){
            int leftindex = 2*i;
            int rightindex = 2*i +1;
            if(leftindex<size && arr[i] < arr[leftindex]){
                int temp = arr[i];
                arr[i] = arr[leftindex];
                arr[leftindex] = temp;
                i = leftindex;
            }
            else if(rightindex < size && arr[i]<arr[rightindex]){
                int temp = arr[i];
                arr[i] = arr[rightindex];
                arr[rightindex] = temp;
                i = rightindex;
            }
            else{
                return;
            }
            // logn
        }
    }
    void print(){
        for(int i=1; i<=size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    void heapify(int arr[], int n, int i){
        int largest = i;
        int left = 2*i;
        int right = 2*i +1;
        if(left <n && arr[left]>arr[largest]){
            largest = left;
        }
        if(right<n && arr[right]>arr[largest]){
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
    
};

int main() {
    heap h;
    h.insert(34);
    h.insert(45);
    h.insert(12);
    h.insert(56);
    h.insert(98);
    h.insert(13);
    h.print();
    h.deletion();
    h.print();
    // heapify will go from n/2 to 0
}
