// very imp 
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int total = 0;
        for(int i=0; i<nums.size(); i++){
            total += nums[i];
        }
        int k = total; // 12 in example
        vector<vector<bool>>dp(nums.size(), vector<bool>(k+1, false));
        for(int i=0; i<nums.size(); i++) dp[i][0] = true;
        if(nums[0]<=k) dp[0][nums[0]] = 1;
        for(int i=1; i<nums.size(); i++){
            for(int j = 1; j<=k; j++){
                bool nottake = dp[i-1][k];
                bool take = true;
                if(nums[i]<=j) take = dp[i-1][k-nums[i]];
                dp[i][j] = take || nottake;
            }
        }
        int mindiff = 1e9;
        for(int i=0; i<=total/2; i++){
            if(dp[nums.size()-1][i]==true){
                mindiff = min(mindiff, total-(2*i));
            }
        }
        return mindiff;
    }
}; 
