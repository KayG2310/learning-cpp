// recursive code --> 2^n 
class Solution {
public:
    bool f(int index, vector<int>& nums, int target, int &cnt){
        if(index<0){
            if(target==0){
                cnt++;
                return true;
            }
            return false;
        }
        bool positive = f(index-1, nums, target-nums[index], cnt);
        bool negative = f(index-1, nums, target+nums[index], cnt);
        return positive || negative;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int cnt = 0;
        f(n-1, nums, target, cnt);
        return cnt;
    }
};


// memoized code tc = n*target, sc = n*target + target 
class Solution {
public:
    bool f(int index, vector<int>& nums, int target, int &cnt, vector<vector<int>>&dp, int m){
        if(index<0){
            if(target==0){
                cnt++;
                return true;
            }
            return false;
        }
        if(dp[index][target-m] != -1) return dp[index][target-m];
        bool positive = f(index-1, nums, target-nums[index], cnt, dp, m);
        bool negative = f(index-1, nums, target+nums[index], cnt, dp, m);
        return dp[index][target-m] = positive || negative;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int cnt = 0;
        int total = 0;
        for(int i=0; i<n; i++){
            total+=nums[i];
        }
        vector<vector<int>>dp(n, vector<int>((2*total)+2, -1));
        int m = target-total;
        f(n-1, nums, target, cnt, dp, m);
        return cnt;
    }
};

