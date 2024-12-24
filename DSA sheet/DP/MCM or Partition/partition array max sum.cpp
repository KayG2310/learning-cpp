// recursive code
class Solution {
private:
    bool pal(int i, int j, string &str){
        while(i<=j){
            if(str[i] != str[j]) return false;
            i++;
            j--;
        }
        return true;
    }
public:
    int minCut(string s) {
        int n = s.length();
        vector<int>dp(n+1, 0);
        for(int i=n-1; i>=0; i--){
            int mincost = INT_MAX;
            for(int j=i; j<n; j++){
                if(pal(i, j, s)){
                    int cost = 1 + dp[j+1];
                    mincost = min(mincost, cost);
                }
            }
            dp[i] = mincost;
        }
        return dp[0]-1;
    }
};

// memoization n^2, sc= n+n
class Solution {
private:
    int f(int ind, int n, int k, vector<int>&arr, vector<int>&dp){
        if(ind==n) return 0;
        if(dp[ind] != -1) return dp[ind];
        int len = 0;
        int maxi = INT_MIN;
        int maxans = INT_MIN;
        for(int j=ind; j<min(n, ind+k); j++){
            len++;
            maxi = max(maxi, arr[j]);
            int sum = len*maxi + f(j+1, n, k, arr, dp);
            maxans = max(maxans, sum);
        }
        return dp[ind] = maxans;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n+1, -1);
        return f(0, n, k, arr, dp);
    }
};

// tabulation 
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n+1, 0);
        for(int ind=n-1; ind>=0; ind--){
            int len = 0;
            int maxi = INT_MIN;
            int maxans = INT_MIN;
            for(int j=ind; j<min(n, ind+k); j++){
                len++;
                maxi = max(maxi, arr[j]);
                int sum = len*maxi + dp[j+1];
                maxans = max(maxans, sum);
            }
            dp[ind] = maxans;
        }
        return dp[0];
    }
};
