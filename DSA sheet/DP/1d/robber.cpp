// basic recursion 2^n pick not pick
class Solution {
public:
    int f(int index, vector<int>&nums){
        if(index == 0){
            // 1st wasn't picked
            return nums[index];
        } 
        if(index <0 ) return 0;
        int pick = nums[index] + f(index-2, nums);
        int notpick = f(index-1, nums);
        return max(pick, notpick);
    }
    int rob(vector<int>& nums) {
        return f(nums.size()-1, nums);
    }
};

// memoization, tc = n, sc = 2n
class Solution {
public:
    int f(int index, vector<int>&nums, vector<int>&dp){
        if(index == 0){
            // 1st wasn't picked
            return nums[index];
        } 
        if(index <0 ) return 0;
        if(dp[index] != -1) return dp[index];
        int pick = nums[index] + f(index-2, nums, dp);
        int notpick = f(index-1, nums, dp);
        return dp[index] = max(pick, notpick);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1, -1);
        return f(nums.size()-1, nums, dp);
    }
};

// bottoms up
class Solution {
public:
    int rob(vector<int>& nums){
        vector<int>dp(nums.size(), -1);
        dp[0] = nums[0];
        for(int i=1; i<nums.size(); i++){
            int pick = nums[i];
            if(i>1){
                pick += dp[i-2];
            }
            int notpick = dp[i-1];
            dp[i] = max(pick, notpick);
        }
        return dp[nums.size()-1];
    }
}; 

// removing that extra space complexity as well
class Solution {
public:
    int rob(vector<int>& nums){
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
};
