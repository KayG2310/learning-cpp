class Solution {
public:
    int rob1(vector<int>& nums){
            int prev1 =  nums[0];
            int prev2 = 0; // for negative
            for(int i=1; i<nums.size(); i++){
                int pick = nums[i];
                if(i>1){
                    pick += prev2;
                }
                int notpick = prev1;
                int temp = max(pick, notpick);
                prev2 = prev1;
                prev1 = temp;
            }
            return prev1;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int>picked, notpicked;
        for(int i=0; i<nums.size()-1; i++){
            picked.push_back(nums[i]);
        }
        for(int i=1; i<nums.size(); i++){
            notpicked.push_back(nums[i]);
        }
        return max(rob1(picked), rob1(notpicked));

    }
};
