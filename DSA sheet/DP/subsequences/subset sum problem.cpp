// recursive code + memoization n.k, (n.k+n)
class Solution {
  public:
    bool f(int index, int sum, vector<int> &arr, vector<vector<int>> &dp){
        if(index<0) return sum==0;
        if(sum == 0) return true;
        if(dp[index][sum] != -1) return dp[index][sum];
        bool pick = false;
        if(sum - arr[index]>=0) pick = f(index-1, sum-arr[index], arr, dp);
        bool notpick = f(index-1, sum, arr, dp);
        return dp[index][sum] = pick || notpick;
    }
    bool isSubsetSum(vector<int> arr, int sum) {
        vector<vector<int>>dp(arr.size(), vector<int>(sum+1,-1));
        return f(arr.size()-1, sum, arr, dp);
    }
};


// tabulation --> n.k , n.k 
class Solution {
  public:
    bool isSubsetSum(vector<int> arr, int sum) {
        vector<vector<int>>dp(arr.size()+1, vector<int>(sum+1,0));
        dp[0][0] = 1;
        for(int i=0; i<=arr.size(); i++){
            dp[i][0] = 1;
        }
        for(int i=1; i<=arr.size(); i++){
            for(int j=0; j<= sum; j++){
                bool pick = false;
                if(j - arr[i-1]>=0) pick = dp[i-1][j-arr[i-1]];
                bool notpick = dp[i-1][j];
                dp[i][j] = pick || notpick;
            }
        }
        return dp[arr.size()][sum];
    }
};

class Solution {
  public:
    bool isSubsetSum(vector<int> arr, int sum) {
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
};
