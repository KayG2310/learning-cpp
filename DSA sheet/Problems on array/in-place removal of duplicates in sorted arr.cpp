// brute force - create a set (not in place)
// optimal is two pointer approach
// 1st pointer is from starting, the second checks the element not equal to first
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int i=0;
      for(int j=1; j< nums.size(); j++){
        if(nums[j] != nums[i]){
            nums[i+1] = nums[j];
            i++;
        }
        
      }
      return i+1;  
    }
};
