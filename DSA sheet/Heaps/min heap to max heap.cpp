class Solution{
    
public:
    void heapify(int i, vector<int> &arr, int n){
        int left = 2*i+1;
        int right = 2*i+2;
        int largest = i;
        if(left <n && arr[left]>arr[largest]) largest = left;
        if(right < n && arr[right]>arr[largest]) largest = right;
        if(largest != i){
            // first swap
            swap(arr[i], arr[largest]);
            heapify(largest, arr, n);
        }
    }
    void convertMinToMaxHeap(vector<int> &arr, int n){
        // reverse(arr.begin(), arr.end());
        for(int i=n/2; i>=0; i--){
            heapify(i, arr, n);
        }
    }
    
};
