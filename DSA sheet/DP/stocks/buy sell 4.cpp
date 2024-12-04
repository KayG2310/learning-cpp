// recursive, tc = exponential, sc = n
class Solution {
public:
    int f(int i, int id, vector<int>& prices, int n, int k, int &profit){
        // base case
        if(i==n) return 0;
        if(id == 2*k) return 0;

        if(id%2==0) {
            // buying possible
            profit = max(f(i+1, id+1, prices, n, k, profit)-prices[i], f(i+1, id, prices, n, k, profit));
        }
        else {
            // selling possible
            profit = max(f(i+1, id+1, prices, n, k, profit)+prices[i], f(i+1, id, prices, n, k, profit));
        }
        return profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        // if k transactions possible, transaction number from 0 to 2k-1
        int profit = 0;
        int n = prices.size();
        return f(0, 0, prices, n, k, profit);
    }
};

// memoized tc = 2*k*n , sc = 2kn + n
class Solution {
public:
    int f(int i, int id, vector<int>& prices, int n, int k, int &profit, vector<vector<int>>&dp){
        // base case
        if(i==n) return 0;
        if(id == 2*k) return 0;
        if(dp[i][id] != -1) return dp[i][id];
        if(id%2==0) {
            // buying possible
            profit = max(f(i+1, id+1, prices, n, k, profit, dp)-prices[i], f(i+1, id, prices, n, k, profit, dp));
        }
        else {
            // selling possible
            profit = max(f(i+1, id+1, prices, n, k, profit, dp)+prices[i], f(i+1, id, prices, n, k, profit, dp));
        }
        return dp[i][id] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        // if k transactions possible, transaction number from 0 to 2k-1
        int profit = 0;
        int n = prices.size();
        vector<vector<int>>dp(n, vector<int>(2*(k+1), -1));
        return f(0, 0, prices, n, k, profit, dp);
    }
};

// tabulation sc reduced by n
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int profit = 0;
        int n = prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2*k+1, 0));

        for(int i=n-1; i>=0; i--){
            for(int id = 2*k-1; id >= 0; id--){
                if(id%2==0) {
                    // buying possible
                    dp[i][id] = max(dp[i+1][id+1]-prices[i], dp[i+1][id]);
                }
                else{
                    dp[i][id] = max(dp[i+1][id+1]+prices[i], dp[i+1][id]);
                }
            }
        }
        return dp[0][0];
    }
}; 

// space opt 
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int profit = 0;
        int n = prices.size();
        // vector<vector<int>>dp(n+1, vector<int>(2*k+1, 0));
        vector<int>cur(2*k+1, 0), ahead(2*k+1, 0);
        for(int i=n-1; i>=0; i--){
            for(int id = 2*k-1; id >= 0; id--){
                if(id%2==0) {
                    // buying possible
                    cur[id] = max(ahead[id+1]-prices[i], ahead[id]);
                }
                else{
                    cur[id] = max(ahead[id+1]+prices[i], ahead[id]);
                }
            }
            ahead = cur;
        }
        return ahead[0];
    }
};
