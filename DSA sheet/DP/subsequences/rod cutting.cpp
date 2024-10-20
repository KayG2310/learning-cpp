// brute force 2^n exponential 
class Solution{
  public:
    int f(int index, int n, int price[]){
        if(index == 0) return n*price[0];
        int nottake = f(index -1, n, price);
        int take = INT_MIN;
        int rodlength = index+1;
        if(rodlength <= n){
            take = price[index]+f(index, n-rodlength, price);
        }
        return max(take, nottake);
        
    }
    int cutRod(int price[], int n) {
        //code here
        return f(n-1, n, price);
    }
};

// memoization n*n+1
class Solution{
  public:
    int f(int index, int n, int price[], vector<vector<int>>&dp){
        if(index == 0) return n*price[0];
        if(dp[index][n] != -1) return dp[index][n];
        int nottake = f(index -1, n, price, dp);
        int take = INT_MIN;
        int rodlength = index+1;
        if(rodlength <= n){
            take = price[index]+f(index, n-rodlength, price, dp);
        }
        return dp[index][n] = max(take, nottake);
        
    }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>dp(n, vector<int>(n+1, -1));
        return f(n-1, n, price, dp);
    }
};


// 
int unboundedKnapsack(int n, int W, vector<int>& val, vector<int>& wt) {
    vector<vector<int>> dp(n, vector<int>(W + 1, 0)); // Create a DP table

    // Base Condition
    for (int i = wt[0]; i <= W; i++) {
        dp[0][i] = (i / wt[0]) * val[0]; // Calculate the maximum value for the first item
    }

    for (int ind = 1; ind < n; ind++) {
        for (int cap = 0; cap <= W; cap++) {
            int notTaken = 0 + dp[ind - 1][cap]; // Maximum value without taking the current item

            int taken = INT_MIN;
            if (wt[ind] <= cap)
                taken = val[ind] + dp[ind][cap - wt[ind]]; // Maximum value by taking the current item

            dp[ind][cap] = max(notTaken, taken); // Store the maximum value in the DP table
        }
    }

    return dp[n - 1][W]; // Return the maximum value considering all items and the knapsack capacity
}


