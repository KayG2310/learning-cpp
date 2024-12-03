// tabulation 
class Solution {
public:
    int minInsertions(string s) {
        string t = "";
        int n = s.length();

        for(int i=n-1; i>=0; i--){
            t+= s[i];
        }
        // reverse copy created 

        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1] == t[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return n-dp[n][n];
    }
};

// space optimised
class Solution {
public:
    int minInsertions(string s) {
        string t = "";
        int n = s.length();

        for(int i=n-1; i>=0; i--){
            t+= s[i];
        }
        // reverse copy created 

        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        vector<int>prev(n+1, 0);
        vector<int>cur(n+1, 0);
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1] == t[j-1]) cur[j] = 1+prev[j-1];
                else cur[j] = max(prev[j], cur[j-1]);
            }
            prev = cur;
        }
        return n-prev[n];
    }
};
