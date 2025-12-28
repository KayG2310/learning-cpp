// number of ways to evaluate to true

// recursive code -- tc = exp
int mod = 1000000007;
// is true denotes if you want current expression range to be true or not
long long f(int i, int j, int isTrue, string &exp){
    if(i>j) return 0;
    if(i==j){
        if(isTrue){
            if(exp[i]=='T') return 1;
            return 0;
        }
        else{
            if(exp[i]=='F') return 1;
            return 0;
        }
    }
    long long ways = 0;
    for(int ind = i+1; ind < j; ind+=2){
        long long lt = f(i, ind-1, 1, exp);
        long long lf = f(i, ind-1, 0, exp);
        long long rt = f(ind+1, j, 1, exp);
        long long rf = f(ind+1, j, 0, exp);
        if(exp[ind] == '&'){
            if(isTrue) ways+=(lt*rt)%mod;
            else ways += ((lt*rf)+(lf*rf)+(lf*rt))%mod;
        }
        else if(exp[ind] == '|'){
            if(isTrue) ways+=((lt*rt)+(lt*rf)+(lf*rt))%mod;
            else ways += (lf*rf)%mod;
        }
        else if(exp[ind] == '^'){
            if(isTrue) ways+=((lt*rf)+(lf*rt))%mod;
            else ways += ((rt*lt)+(lf*rf))%mod;
        }
    }
    return ways%mod;
}
int evaluateExp(string & exp) {
    // Write your code here.
    return f(0, exp.length()-1, 1, exp);

}
// memoized tc = n^3 * 2, sc = 2n^2+a.s.s
int mod = 1000000007;
long long f(int i, int j, int isTrue, string &exp, vector<vector<vector<int>>>&dp){
    if(i>j) return 0;
    if(i==j){
        if(isTrue){
            if(exp[i]=='T') return 1;
            return 0;
        }
        else{
            if(exp[i]=='F') return 1;
            return 0;
        }
    }
    if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
    long long ways = 0;
    for(int ind = i+1; ind < j; ind+=2){
        long long lt = f(i, ind-1, 1, exp, dp);
        long long lf = f(i, ind-1, 0, exp, dp);
        long long rt = f(ind+1, j, 1, exp, dp);
        long long rf = f(ind+1, j, 0, exp, dp);
        if(exp[ind] == '&'){
            if(isTrue) ways+=(lt*rt)%mod;
            else ways += ((lt*rf)+(lf*rf)+(lf*rt))%mod;
        }
        else if(exp[ind] == '|'){
            if(isTrue) ways+=((lt*rt)+(lt*rf)+(lf*rt))%mod;
            else ways += (lf*rf)%mod;
        }
        else if(exp[ind] == '^'){
            if(isTrue) ways+=((lt*rf)+(lf*rt))%mod;
            else ways += ((rt*lt)+(lf*rf))%mod;
        }
    }
    return dp[i][j][isTrue] = ways%mod;
}
int evaluateExp(string & exp) {
    // Write your code here.
    int n = exp.length();
    vector<vector<vector<int>>>dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
    return f(0, n-1, 1, exp, dp);

}

// tabulation 
int mod = 1000000007;
int evaluateExp(string & exp) {
    // Write your code here.
    int n = exp.length();
    vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(n+1, vector<int>(2, 0)));
    for(int i=0; i<n; i++){
        if(exp[i]=='T') dp[i][i][1] = 1;
        if(exp[i]=='F') dp[i][i][0] = 1;
            
    }
    for(int i=n-1; i>=0; i--){
        for(int j=0; j<n; j++){
            if(i>j) continue;
            long long ways = 0;
            for(int isTrue=1; isTrue>=0; isTrue--){
                for(int ind = i+1; ind < j; ind+=2){
                    long long lt = dp[i][ind-1][1];
                    long long lf = dp[i][ind-1][0];
                    long long rt = dp[ind+1][j][1];
                    long long rf = dp[ind+1][j][0];
                    if(exp[ind] == '&'){
                        if(isTrue) ways+=(lt*rt)%mod;
                        else ways += ((lt*rf)+(lf*rf)+(lf*rt))%mod;
                    }
                    else if(exp[ind] == '|'){
                        if(isTrue) ways+=((lt*rt)+(lt*rf)+(lf*rt))%mod;
                        else ways += (lf*rf)%mod;
                    } else if (exp[ind] == '^') {
                        if (isTrue)
                        ways += ((lt * rf) + (lf * rt)) % mod;
                        else
                        ways += ((rt * lt) + (lf * rf)) % mod;
                    }
                }
                dp[i][j][isTrue] = ways % mod;
            }
        }
    }
    return dp[0][n-1][1];

} 

// tabulation gave wrong answer, can be figured out later ig
