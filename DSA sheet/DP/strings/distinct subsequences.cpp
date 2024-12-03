// recursive code
class Solution {
public:
    int f(int i, int j, string &s, string &t){
        if(j<0) return 1;
        if(i<0) return 0; 
        // smaller got exhausted means it was found 
        if(s[i]==t[j]) return f(i-1, j-1, s, t) + f(i-1, j, s, t);
        return f(i-1, j, s, t);

    }
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        return f(n-1, m-1, s, t);
    }
}; 

// memoized tc = n*m, sc = n*m + (n+m) 
class Solution {
public:
    int f(int i, int j, string &s, string &t, vector<vector<int>>&dp){
        if(j<0) return 1;
        if(i<0) return 0; 
        // smaller got exhausted means it was found 
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i]==t[j]) return dp[i][j] = f(i-1, j-1, s, t, dp) + f(i-1, j, s, t, dp);
        return dp[i][j] = f(i-1, j, s, t, dp);

    }
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return f(n-1, m-1, s, t, dp);
    }
}; 

// tabulation
const int mod = 1e9+7;
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        for(int i=0; i<=n; i++) dp[i][0] = 1;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1]==t[j-1]) dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%mod;
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][m];
    }
}; 

// space opt canbe done
