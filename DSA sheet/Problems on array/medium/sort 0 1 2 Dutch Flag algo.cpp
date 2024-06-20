// brute force approach - sort the array, takes n log n
// better approach
#include<bits/stdc++.h>
using namespace std;

int main() {
    int arr[12] = {0,1,2,0,1,2,1,2,0,0,0,1};
    int count0=0, count1 = 0, count2=0;
    int n = sizeof(arr)/sizeof(int);
    for(int i=0; i<n;i++){
        if(arr[i]==0){
            count0++;
        }
        else if(arr[i]==1){
            count1++;
        }
        else{
            count2++;
        }
    }
    
    for(int i=0; i<count0; i++){
        arr[i] = 0;
    }
    for(int i=count0; i<count1+count0;i++){
        arr[i] = 1;
    }
    for(int i=count1+count0;i<n;i++){
        arr[i] = 2;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    // time complexity = O(2N)
    // space complexity = O(1)
}


// best appraoch - Dutch National Flag algo
#include<bits/stdc++.h>
using namespace std;

int main() {
    int arr[12] = {0,1,2,0,1,2,1,2,0,0,0,1};
    int low=0, mid=0, high = 11;
    // high =n here n is 12
    while(mid<=high){
        // case1
        if(arr[mid]==0){
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        // case2
        else if(arr[mid]==1){
            mid++;
        }
        // case3
        else{
            swap(arr[high], arr[mid]);
            high--;
        }
    }
    
    for(int i=0; i<12; i++){
        cout<<arr[i]<<" ";
    }
    
    // time complexity = O(N)
    // space complexity = O(1)
}
