// 2 pass solution tc = 2n, sc = 1
class Solution {
public:
    bool check(vector<int>& nums) {
        
        int index = -1;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]> nums[i+1]){
                // it is a rotation point
                index = i;
                break;
            }
        }
        if(index == -1){
            // no rotation found
            for(int i=0; i<nums.size()-1; i++){
                if(nums[i]> nums[i+1]){
                    return false;
                }
            }
        }
        else{
            if(nums[nums.size()-1]>nums[0]) return false;
            // there was some rotation
            for(int i=index+1; i<nums.size()-1; i++){
                if(nums[i]> nums[i+1]){
                    return false;
                }
            }
            
            for(int i=0; i<index; i++){
                if(nums[i]> nums[i+1]){
                    return false;
                }
            }
        }
        return true;
    }
};
/*
dry run -->
2 1 3 4
i = 0 3 not > 4 nothing
i = 1 4 not > 5 nothing
i = 2, 5 > 1 index = 2
*/


// one pass solution
