class Solution {
private:

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int ub = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        int lb = lower_bound(nums.begin(), nums.end(), target) - nums.begin();   
        if(lb == nums.size() || nums[lb] != target){
            return {-1,-1};
        }
        return {lb,ub-1};
    }
};

// if the interviewer does not know lower and upper bound, we need to be ready with a simple binary search code
#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[] = {2,8,8,8,8,8,11,13};
    int n = sizeof(arr)/sizeof(int);
    
    int target = 8;
    int low=0, high = n-1;
    int mid = 0;
    int first = -1, last = -1; 
    while(low<=high){
        mid = (low+high)/2;
        if(arr[mid]==target){
            first = mid;
            high = mid-1;
        }
        else if(arr[mid]>target){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    // if(first==-1) return {-1,-1};
    low=0; high = n-1;
    mid = 0;
    while(low<=high){
        mid = (low+high)/2;
        if(arr[mid]==target){
            last = mid;
            low = mid+1;
        }
        else if(arr[mid]>target){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    cout<<first<<" "<<last;
}
