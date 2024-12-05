class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        int l = 0;
        vector<int>dp(n, 1), hash(n);
        int maxi = 1;
        for(int i=0; i<n; i++){
            hash[i] = i;
            for(int p=0;  p<i; p++){
                if(arr[p] < arr[i] && 1+dp[p]>dp[i]){
                    dp[i] = 1+dp[p];
                    hash[i] = p;
                }
            }
            if(dp[i]>maxi){
                maxi = dp[i];
                l = i;
            }
        }
        vector<int> lis;
        lis.push_back(arr[l]);
        while(hash[l] != l){
            l = hash[l];
            lis.push_back(arr[l]);
        }
        reverse(lis.begin(), lis.end());
        return lis;
    }
}; 
