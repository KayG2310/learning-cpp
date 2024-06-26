// leetcode submission
class Solution {
public:
    int findMin(vector<int>& nums) {
        return *min_element(nums.begin(), nums.end());
    }
};

#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {7,8,9,1,2,3,4,5};
    int n= sizeof(arr)/sizeof(int);
    
    int low=0, high= n-1, mid = 0;
    int ans = INT_MAX;
    while(low<=high){
        // this is always going to be our breaking condition
        mid = (low+high)/2;
        if(arr[low]<=arr[mid]){
            // it means the left half is sorted
            ans = min(ans, arr[low]);
            low = mid+1;
        }
        // then we go to right half
        else{
            ans = min(ans, arr[mid]);
            high = mid-1;
        }
    }
}
