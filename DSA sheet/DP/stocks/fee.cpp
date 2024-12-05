// recursive tc = exp, sc = n
class Solution {
public:
    int f(int i, int buy, vector<int>& prices, int fee, int &profit){
        if(i==prices.size()) return 0;
        if(buy){
            profit = max(f(i+1, 0, prices, fee, profit)-prices[i]-fee, f(i+1, 1, prices, fee, profit));
        }
        else{
            profit = max(f(i+1, 1, prices, fee, profit)+prices[i], f(i+1, 0, prices, fee, profit));
        }
        return profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int profit = 0;
        return f(0,1, prices, fee, profit);
    }
}; 

// memoized tc = 2n, sc = 2n+n
class Solution {
public:
    int f(int i, int buy, vector<int>& prices, int fee, int &profit, vector<vector<int>>&dp){
        if(i==prices.size()) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        if(buy){
            profit = max(f(i+1, 0, prices, fee, profit, dp)-prices[i]-fee, f(i+1, 1, prices, fee, profit, dp));
        }
        else{
            profit = max(f(i+1, 1, prices, fee, profit, dp)+prices[i], f(i+1, 0, prices, fee, profit, dp));
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int profit = 0;
        int n = prices.size();
        vector<vector<int>>dp(n, vector<int>(2, -1));
        return f(0,1, prices, fee, profit, dp);
    }
}; 

// tabulation tc = 2n, sc = 2n
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int profit = 0;
        int n = prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2, 0));
        // base case already handled

        for(int i=n-1; i>=0; i--){
            for(int buy = 0; buy<2; buy++){
                if(buy){
                    profit = max(dp[i+1][0]-prices[i]-fee, dp[i+1][1]);
                }
                else{
                    profit = max(dp[i+1][1]+prices[i], dp[i+1][0]);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }
}; 

// space optimisation
