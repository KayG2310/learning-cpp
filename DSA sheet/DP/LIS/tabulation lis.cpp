// tabulation approach -->
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));

        for(int i=n-1; i>=0; i--){
            for(int prev = i-1; prev>=-1; prev--){
                int len = dp[i+1][prev+1]; // not taking
                if(prev == -1 || nums[i]>nums[prev]){
                    len = max(len, 1+ dp[i+1][i+1]);
                }
                dp[i][prev+1] = len;
            }
        }
        return dp[0][0];
    }
}; 

// space optimisation 
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>cur(n+1, 0), ahead(n+1, 0);

        for(int i=n-1; i>=0; i--){
            for(int prev = i-1; prev>=-1; prev--){
                int len = ahead[prev+1]; // not taking
                if(prev == -1 || nums[i]>nums[prev]){
                    len = max(len, 1+ ahead[i+1]);
                }
                cur[prev+1] = len;
            }
            ahead = cur;
        }
        return ahead[0];
    }
}; 

// space opt from 2n to n
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>ahead(n+1, 0);

        for(int i=n-1; i>=0; i--){
            for(int prev = i-1; prev>=-1; prev--){
                int len = ahead[prev+1]; // not taking
                if(prev == -1 || nums[i]>nums[prev]){
                    len = max(len, 1+ ahead[i+1]);
                }
                ahead[prev+1] = len;
            }
            // ahead = cur;
        }
        return ahead[0];
    }
};

// final
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, 1);
        int maxi = 1;
        for(int i=0; i<n; i++){
            for(int p=0; p<i; p++){
                if(nums[p]<nums[i]){
                    dp[i] = max(dp[i], 1+dp[p]);
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};
