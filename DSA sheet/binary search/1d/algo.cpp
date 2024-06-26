// iterative approach ---> submitted on leetcode
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low=0, high = n-1;
        int mid = 0;
        bool flag = false;
        while(low<=high){
            mid = (low+high)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return -1;
    }
};

// recursive approach 
#include<bits/stdc++.h>
using namespace std;

int binary(int arr[], int low, int high, int target){
    if(low>high) return -1;
    int mid = (low+high)/2;
    if(arr[mid]==target){
        return mid;
    }
    else if(arr[mid]>target){
        high = mid-1;
        return binary(arr, low,high,target);
    }
    else{
        low = mid+1;
        return binary(arr, low,high,target);
    }
}


int main(){
    int arr[] = {3,4,6,7,9,12,14,16,17};
    int n = sizeof(arr)/sizeof(int);
    
    int target = 14;
    int low=0, high = n-1;
    cout<<binary(arr, low,high,target);
}

// TC --> log n


// overflow condition use long long or mid = low + (high-low)/2
