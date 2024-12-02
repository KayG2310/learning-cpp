// recursive code
class Solution {
public:
    int f(int index, vector<int>& coins, int amount){
        if(amount==0) return 1;
        if(index==0) {
            if(amount%coins[0]==0) return 1;
            return 0;
        }
        
        int notpick = f(index-1, coins, amount);
        int pick = 0;
        if(coins[index]<= amount) pick = f(index, coins, amount-coins[index]);
        return pick+notpick;
    }
    int change(int amount, vector<int>& coins) {
        int x = f(coins.size()-1, coins, amount);
        return x;
    }
}; 

// memoized 
class Solution {
public:
    int f(int index, vector<int>& coins, int amount, vector<vector<int>>&dp){
        if(amount==0) return 1;
        if(index==0) {
            if(amount%coins[0]==0) return 1;
            return 0;
        }
        if(dp[index][amount] != -1) return dp[index][amount];
        int notpick = f(index-1, coins, amount, dp);
        int pick = 0;
        if(coins[index]<= amount) pick = f(index, coins, amount-coins[index], dp);
        return dp[index][amount] = pick+notpick;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        f(n-1, coins, amount, dp);
        return f(n-1, coins, amount, dp);
    }
}; 

// tabulation
const uint mod = 1e10+7;
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<long long>>dp(n, vector<long long>(amount+1, 0));

        // base case 1
        for(int i=0; i<n; i++){
            dp[i][0] = 1;
        }
        for(int i=0; i<=amount; i++){
            if(i%coins[0]==0) dp[0][i] = 1;

        }

        for(int index=1; index<n; index++){
            for(int amt = 1; amt<=amount; amt++){
                uint notpick = dp[index-1][amt]%mod;
                uint pick = 0;
                if(coins[index]<= amt) pick = dp[index][amt-coins[index]]%mod;
                dp[index][amt] = (pick+notpick)%mod;
            }
        }
        return dp[n-1][amount];
    }
}; 

// space opt
const uint mod = 1e10+7;
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // base case 1
        vector<int>prev(amount+1, 0);
        vector<int>cur(amount+1, 0);
        prev[0] = 1;
        cur[0] = 1;
        for(int i=0; i<=amount; i++){
            if(i%coins[0]==0) prev[i] = 1;
            if(i%coins[0]==0) cur[i] = 1;
        }

        for(int index=1; index<n; index++){
            for(int amt = 1; amt<=amount; amt++){
                uint notpick = prev[amt]%mod;
                uint pick = 0;
                if(coins[index]<= amt) pick = cur[amt-coins[index]]%mod;
                cur[amt] = (pick+notpick)%mod;
            }
            prev = cur;
        }
        return prev[amount];
    }
};
