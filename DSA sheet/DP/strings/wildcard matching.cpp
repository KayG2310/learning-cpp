class Solution {
public:
    bool f(int i, int j, string &s, string &p){
        if(i<0 && j<0) return true;
        if(i>=0 && j<0) return false;
        if(j>=0 && i<0){
            for(int ii=0; ii<=j; ii++){
                if(p[ii] != '*') return false;
            }
            return true;
        }
        if(s[i]==p[j] || p[j]=='?') return f(i-1, j-1, s, p);
        if(p[j]=='*') return f(i-1, j, s, p) || f(i, j-1, s, p);
        return false;
    }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();

        return f(n-1, m-1, s, p);
    }
};

// memoized code
class Solution {
public:
    bool f(int i, int j, string &s, string &p, vector<vector<int>>&dp){
        if(i<0 && j<0) return true;
        if(i>=0 && j<0) return false;
        if(j>=0 && i<0){
            for(int ii=0; ii<=j; ii++){
                if(p[ii] != '*') return false;
            }
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i]==p[j] || p[j]=='?') return dp[i][j] = f(i-1, j-1, s, p, dp);
        if(p[j]=='*') return dp[i][j] = f(i-1, j, s, p, dp) || f(i, j-1, s, p, dp);
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return f(n-1, m-1, s, p, dp);
    }
}; 


// tabulation
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<bool>>dp(n+1, vector<bool>(m+1, false));
        dp[0][0] = 1;
        for(int i=1; i<=m; i++){
            int flag = true;
            for(int ii=1; ii<=i; ii++){
                if(p[ii-1] != '*'){
                    flag = false;
                    break;
                }
            }
            dp[0][i] = flag; 
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?') dp[i][j] = dp[i-1][j-1];
                else if(p[j-1]=='*') dp[i][j] = dp[i-1][j] || dp[i][j-1];
                else dp[i][j] = false;
            }
        }
        return dp[n][m];
    }
}; 

// can be space optimized
