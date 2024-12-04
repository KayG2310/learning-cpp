// recursive code , tc = 2^n, sc = n
class Solution {
public:
    int f(int index, int buy, int &profit, vector<int>& prices, int n){
        if(index == n) return 0;
        if(buy){
            profit = max(f(index+1, 0, profit, prices, n)-prices[index], f(index+1, 1, profit, prices, n));
        }
        else{
            profit = max(f(index+1, 1, profit, prices, n)+prices[index], f(index+1,0, profit, prices, n));
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        f(0, 1, profit, prices, n);
        return profit;
    }
};

// memoized code tc = n*2, sc = n*2 + n
class Solution {
public:
    int f(int index, int buy, int &profit, vector<int>& prices, int n, vector<vector<int>>&dp){
        if(index == n) return 0;
        if(dp[index][buy] != -1) return dp[index][buy];
        if(buy){
            profit = max(f(index+1, 0, profit, prices, n, dp)-prices[index], f(index+1, 1, profit, prices, n, dp));
        }
        else{
            profit = max(f(index+1, 1, profit, prices, n, dp)+prices[index], f(index+1,0, profit, prices, n, dp));
        }
        return dp[index][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        vector<vector<int>>dp(n, vector<int>(2, -1));
        f(0, 1, profit, prices, n, dp);
        return profit;
    }
};

// tabulation code to remove auxiliary stack space, tc = 2*n, sc = 2*n
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        vector<vector<int>>dp(n+1, vector<int>(2, 0));
        // base case already handled
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<2; j++){
                if(j==1){
                    profit = max(dp[i+1][0]-prices[i], dp[i+1][1]);
                }
                else{
                    profit = max(dp[i+1][1]+prices[i], dp[i+1][0]);
                }
                dp[i][j] = profit;
            }
        }
        return profit;
    }
}; 

// space optimisation tc = 2n, sc = 1
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        // vector<vector<int>>dp(n+1, vector<int>(2, 0));
        vector<int>cur(2,0), next(2,0);
        // base case already handled
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<2; j++){
                if(j==1){
                    profit = max(next[0]-prices[i], next[1]);
                }
                else{
                    profit = max(next[1]+prices[i], next[0]);
                }
                cur[j] = profit;
            }
            next = cur;
        }
        return profit;
    }
};
