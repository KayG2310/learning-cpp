// recursive code = 2^n 
class Solution {
public:
    int f(int index, vector<int>& coins, int amount){
        if(amount==0) return 0;
        if(index==0) {
            if(amount%coins[0]==0) return amount/coins[0];
            return 1e9;
        }
        
        int notpick = f(index-1, coins, amount);
        int pick = 1e9;
        if(coins[index]<= amount) pick = 1+ f(index, coins, amount-coins[index]);
        // cout<<index<<" "<<pick<<" "<<notpick<<" "<<amount<<endl;
        // if(notpick==0 || pick==0) return max(pick, notpick);
        
        return min(pick, notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int x = f(coins.size()-1, coins, amount);
        return (x==1e9) ? -1 : x;
        return f(coins.size()-1, coins, amount);

    }
}; 

// memoized code , tc = n*amount, sc = n*amount + amount -- ASC
class Solution {
public:
    int f(int index, vector<int>& coins, int amount, vector<vector<int>>&dp){
        if(amount==0) return 0;
        if(index==0) {
            if(amount%coins[0]==0) return amount/coins[0];
            return 1e9;
        }
        if(dp[index][amount] != -1) return dp[index][amount];
        int notpick = f(index-1, coins, amount, dp);
        int pick = 1e9;
        if(coins[index]<= amount) pick = 1+ f(index, coins, amount-coins[index], dp);
        return dp[index][amount] = min(pick, notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        int x = f(coins.size()-1, coins, amount, dp);
        return (x==1e9) ? -1 : x;

    }
};

// tabulation tc = n*amount, sc = n*amount
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, 0));
        for(int i=0; i<=amount; i++){
            if(i%coins[0]==0) dp[0][i] = i/coins[0];
            else dp[0][i] = 1e9;
        }

        for(int index=1; index<n; index++){
            for(int amt = 1; amt<=amount; amt++){
                int notpick = dp[index-1][amt];
                int pick = 1e9;
                if(coins[index]<= amt) pick = 1+ dp[index][amt-coins[index]];
                dp[index][amt] = min(pick, notpick);
            }
        }
        int x = dp[coins.size()-1][amount];
        return (x==1e9) ? -1 : x;

    }
};


// space optimised code tc = n*amount, sc = amount
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int>prev(amount+1, 0);
        vector<int>cur(amount+1, 0);
        for(int i=0; i<=amount; i++){
            if(i%coins[0]==0) prev[i] = i/coins[0];
            else prev[i] = 1e9;
            if(i%coins[0]==0) cur[i] = i/coins[0];
            else cur[i] = 1e9;
        }

        for(int index=1; index<n; index++){
            for(int amt = 1; amt<=amount; amt++){
                int notpick = prev[amt];
                int pick = 1e9;
                if(coins[index]<= amt) pick = 1+ cur[amt-coins[index]];
                cur[amt] = min(pick, notpick);
            }
            prev = cur;
        }
        int x = prev[amount];
        return (x==1e9) ? -1 : x;

    }
}; 
