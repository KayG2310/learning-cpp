// recursive code tc = exponential
class Solution{
public:
    int f(int i, int j, int arr[]){
        if(i==j) return 0;
        int mini = INT_MAX;
        for(int k = i; k<j; k++){
            int steps = arr[i-1]*arr[k]*arr[j];
            steps = steps+f(i, k, arr)+f(k+1, j, arr);
            mini = min(mini, steps);
        }
        return mini;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        return f(1, N-1, arr);
    }
};

// memoized code tc = n*n*n(for k)
class Solution{
public:
    int f(int i, int j, int arr[], vector<vector<int>>&dp){
        if(i==j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mini = INT_MAX;
        for(int k = i; k<j; k++){
            int steps = arr[i-1]*arr[k]*arr[j];
            steps = steps+f(i, k, arr, dp)+f(k+1, j, arr, dp);
            mini = min(mini, steps);
        }
        return dp[i][j] = mini;
    }
    int matrixMultiplication(int n, int arr[])
    {
        // code here
        vector<vector<int>>dp(n, vector<int>(n,-1));
        return f(1, n-1, arr, dp);
    }
};
