// recursive, tc = exponential, sc = n
class Solution {
public:
    int f(int index, int buy, int cap, vector<int>& prices, int &profit, int n){
        if(cap == 0) return 0;
        if(index == n) return 0;

        if(buy){
            profit = max(f(index+1, 0, cap, prices, profit, n)-prices[index], f(index+1, 1, cap, prices, profit, n));
        }
        else{
            profit = max(f(index+1, 1, cap-1, prices, profit, n)+prices[index], f(index+1, 0, cap, prices, profit, n));
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        f(0, 1, 2, prices, profit, n);
        return profit;
    }
}; 

// memoization, tc = n*2*3, sc = n*2*3 + n
class Solution {
public:
    int f(int index, int buy, int cap, vector<int>& prices, int &profit, int n, vector<vector<vector<int>>>&dp){
        if(cap == 0) return 0;
        if(index == n) return 0;
        if(dp[index][buy][cap] != -1) return dp[index][buy][cap];
        if(buy){
            profit = max(f(index+1, 0, cap, prices, profit, n, dp)-prices[index], f(index+1, 1, cap, prices, profit, n, dp));
        }
        else{
            profit = max(f(index+1, 1, cap-1, prices, profit, n, dp)+prices[index], f(index+1, 0, cap, prices, profit, n, dp));
        }
        return dp[index][buy][cap] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        f(0, 1, 2, prices, profit, n, dp);
        return profit;
    }
}; 

// tabulation tc = 6n, sc = 6n
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        for(int index=n-1; index>=0; index--){
            for(int buy = 0; buy <=1; buy++){
                for(int cap = 1; cap <=2; cap++){
                    if(buy){
                        dp[index][buy][cap] = max(dp[index+1][0][cap]-prices[index], dp[index+1][1][cap]);
                    }
                    else{
                        dp[index][buy][cap] = max(dp[index+1][1][cap-1]+prices[index], dp[index+1][0][cap]);
                    }
                }
            }
        }
        return dp[0][1][2];
    }
};

// space optimise
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        vector<vector<int>>cur(2, vector<int>(3, 0)), ahead(2, vector<int>(3,0));

        for(int index=n-1; index>=0; index--){
            for(int buy = 0; buy <=1; buy++){
                for(int cap = 1; cap <=2; cap++){
                    if(buy){
                        cur[buy][cap] = max(ahead[0][cap]-prices[index], ahead[1][cap]);
                    }
                    else{
                        cur[buy][cap] = max(ahead[1][cap-1]+prices[index], ahead[0][cap]);
                    }
                }
                ahead = cur;
            }
        }
        return cur[1][2];
    }
}; 

// check dp n*4 solution using transaction id
