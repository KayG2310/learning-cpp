// recursive 2^n , sc = n
class Solution {
public:
    int f(int i, int id, vector<int>& prices, int &profit, int n){
        if(i==n) return 0;
        // since infinite transactions can me made, there's no cap
        if(id%3 == 0){
            // buying is possible
            profit = max(f(i+1, id+1, prices, profit, n)-prices[i], f(i+1, id, prices,profit, n));
            // buy or not buy
        }
        else if(id%3 == 1){
            // selling possible
            profit = max(f(i+1, id+1, prices, profit, n)+prices[i], f(i+1, id, prices,profit, n));
            // sell or not sell
        }
        else {
            // cooldown period
            profit = f(i+1, id+1, prices, profit, n);
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int n = prices.size();
        return f(0, 0, prices, profit, n);
    }
};


// memoized code tc = n^2, sc = n^2 + n
class Solution {
public:
    int f(int i, int id, vector<int>& prices, int &profit, int n, vector<vector<int>>&dp){
        if(i==n) return 0;
        // since infinite transactions can me made, there's no cap
        if(dp[i][id] != -1) return dp[i][id];
        if(id%3 == 0){
            // buying is possible
            profit = max(f(i+1, id+1, prices, profit, n, dp)-prices[i], f(i+1, id, prices,profit, n, dp));
            // buy or not buy
        }
        else if(id%3 == 1){
            // selling possible
            profit = max(f(i+1, id+1, prices, profit, n, dp)+prices[i], f(i+1, id, prices,profit, n, dp));
            // sell or not sell
        }
        else {
            // cooldown period
            profit = f(i+1, id+1, prices, profit, n, dp);
        }
        return dp[i][id] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int n = prices.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        return f(0, 0, prices, profit, n, dp);
    }
};

// tabulation tc = n^2, sc = n^2
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int n = prices.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        // base case already handled

        for(int i=n-1; i>=0; i--){
            for(int id = n-1; id>=0; id--){
                if(id%3 == 0){
                    // buying is possible
                    dp[i][id] = max(dp[i+1][id+1]-prices[i], dp[i+1][id]);
                    // buy or not buy
                }
                else if(id%3 == 1){
                    // selling possible
                    dp[i][id] = max(dp[i+1][id+1]+prices[i], dp[i+1][id]);
                    // sell or not sell
                }
                else {
                    // cooldown period
                    dp[i][id] = dp[i+1][id+1];
                }
            }
        }
        return dp[0][0];
    }
};


// space optimisation tc  = n^2, sc = 2n
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int n = prices.size();
        // base case already handled
        vector<int>cur(n+1, 0), ahead(n+1, 0);
        for(int i=n-1; i>=0; i--){
            for(int id = n-1; id>=0; id--){
                if(id%3 == 0){
                    // buying is possible
                    cur[id] = max(ahead[id+1]-prices[i], ahead[id]);
                    // buy or not buy
                }
                else if(id%3 == 1){
                    // selling possible
                    cur[id] = max(ahead[id+1]+prices[i], ahead[id]);
                    // sell or not sell
                }
                else {
                    // cooldown period
                    cur[id] = ahead[id+1];
                }
            }
            ahead = cur;
        }
        return ahead[0];
    }
};
