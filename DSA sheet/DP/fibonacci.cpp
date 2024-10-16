const int mod = 1e9+7;
class Solution {
  public:
    long long f(int n, vector<long long>& dp) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (dp[n] != -1) return dp[n]%mod;
        return dp[n] = (f(n - 1, dp) + f(n - 2, dp))%mod;
    }

    long long int topDown(int n) {
        // Memoization
        vector<long long> dp(n + 1, -1);
        return f(n, dp);
    }

    long long int bottomUp(int n) {
        // Handle base cases explicitly
        if (n == 0) return 0;
        if (n == 1) return 1;

        // Tabular approach
        long long prev2 = 0;
        long long prev = 1;
        for (int i = 2; i <= n; i++) {
            long long s = (prev2 + prev)%mod;
            prev2 = prev;
            prev = s;
        }
        return prev;
    }
};
