class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // vector<vector<int>>dp(arr.size()+1, vector<int>(sum+1,0));
        vector<int> prev(sum+1, 0), cur(sum+1, 0);
        prev[0] = 1;
        for(int i=1; i<=arr.size(); i++){
            for(int j=0; j<= sum; j++){
                bool pick = false;
                if(j - arr[i-1]>=0) pick = prev[j-arr[i-1]];
                bool notpick = prev[j];
                cur[j] = pick || notpick;
            }
            prev = cur;
        }
        return prev[sum];
    }
    bool canPartition(vector<int>& nums) {
        int s = 0;
        for(int i=0; i<nums.size(); i++){
            s+=nums[i];
        }
        if(s%2 != 0) return false;
        return isSubsetSum(nums, s/2);

    }
};
