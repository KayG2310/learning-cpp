// array might have duplicates in this case
// if there are duplicates, chances are arr[low] == arr[mid] = arr[high]
// hence it cannot be decided which the sorted half is
// on leetcode submitted brute force

// some part is same as rotated-i
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1, mid = 0;
        
        while(low<=high){
            mid = (low+high)/2;
            if(nums[mid]==target) return mid;
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                low++;
                high--;
                continue;
            }
            if(nums[low]<=nums[mid]){
                if(nums[low]<=target && nums[mid]>= target){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
                
            }

            else{
                if(nums[mid]<=target && nums[high]>=target){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
        }
        return -1;
    }
};
