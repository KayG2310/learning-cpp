// recursive 
class Solution {
  public:
    int f(int index, int capacity, vector<int>& val, vector<int>& wt){
        if(index == 0){
            return ((int)(capacity/wt[0]))*val[0];
        }
        int notpick = f(index-1, capacity, val, wt);
        int pick = INT_MIN;
        if(wt[index]<=capacity) pick = val[index] + f(index, capacity-wt[index], val, wt);
        return max(pick, notpick);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        return f(n-1, capacity, val, wt);
    }
};

// memoized
class Solution {
  public:
    int f(int index, int capacity, vector<int>& val, vector<int>& wt,
        vector<vector<int>>&dp){
        if(index == 0){
            return ((int)(capacity/wt[0]))*val[0];
        }
        if(dp[index][capacity] != -1) return dp[index][capacity];
        int notpick = f(index-1, capacity, val, wt, dp);
        int pick = INT_MIN;
        if(wt[index]<=capacity) pick = val[index] + f(index, capacity-wt[index], val, wt, dp);
        return dp[index][capacity] = max(pick, notpick);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<vector<int>>dp(n, vector<int>(capacity+1, -1));
        return f(n-1, capacity, val, wt, dp);
    }
}; 

// tabulation 
class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<vector<int>>dp(n, vector<int>(capacity+1, 0));
        for(int i=0; i<=capacity; i++){
            dp[0][i] = ((int)(i/wt[0]))*val[0];
        }
        
        for(int i=1; i<n; i++){
            for(int j=0; j<=capacity; j++){
                int notpick = dp[i-1][j];
                int pick = INT_MIN;
                if(wt[i]<=j) pick = val[i] + dp[i][j-wt[i]];
                dp[i][j] = max(pick, notpick);
            }
        }
        return dp[n-1][capacity];
    }
};

//space opt
class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<int>prev(capacity+1, 0);
        vector<int>cur(capacity+1, 0);
        for(int i=0; i<=capacity; i++){
            prev[i] = ((int)(i/wt[0]))*val[0];
            cur[i] = ((int)(i/wt[0]))*val[0];
        }
        
        for(int i=1; i<n; i++){
            for(int j=0; j<=capacity; j++){
                int notpick = prev[j];
                int pick = INT_MIN;
                if(wt[i]<=j) pick = val[i] + cur[j-wt[i]];
                cur[j] = max(pick, notpick);
            }
            prev = cur;
        }
        return prev[capacity];
    }
};


// space opt further
class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<int>prev(capacity+1, 0);
        // vector<int>cur(capacity+1, 0);
        for(int i=0; i<=capacity; i++){
            prev[i] = ((int)(i/wt[0]))*val[0];
            // cur[i] = ((int)(i/wt[0]))*val[0];
        }
        
        for(int i=1; i<n; i++){
            for(int j=0; j<=capacity; j++){
                int notpick = prev[j];
                int pick = INT_MIN;
                if(wt[i]<=j) pick = val[i] + prev[j-wt[i]];
                prev[j] = max(pick, notpick);
            }
        }
        return prev[capacity];
    }
}; 
