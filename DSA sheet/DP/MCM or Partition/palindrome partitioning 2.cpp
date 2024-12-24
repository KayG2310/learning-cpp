// recursive code tc = exp
// why -1 in the end --> because last partition after n-1th element makes no sense
class Solution {
private:
    bool pal(int i, int j, string &str){
        while(i<=j){
            if(str[i] != str[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int f(int i, int n, string& s){
        if(i==n) return 0;
        int mincost = INT_MAX;
        for(int j=i; j<n; j++){
            if(pal(i, j, s)){
                int cost = 1 + f(j+1, n, s);
                mincost = min(mincost, cost);
            }
        }
        return mincost;
    }
public:
    int minCut(string s) {
        int n = s.length();
        return f(0, n, s)-1;
    }
};


// memoized code tc = n^3 // vector wali, j wala, palindrome wala sc = n+n 
class Solution {
private:
    bool pal(int i, int j, string &str){
        while(i<=j){
            if(str[i] != str[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int f(int i, int n, string& s, vector<int>&dp){
        if(i==n) return 0;
        if(dp[i] != -1) return dp[i];
        int mincost = INT_MAX;
        for(int j=i; j<n; j++){
            if(pal(i, j, s)){
                int cost = 1 + f(j+1, n, s, dp);
                mincost = min(mincost, cost);
            }
        }
        return dp[i] = mincost;
    }
public:
    int minCut(string s) {
        int n = s.length();
        vector<int>dp(n, -1);
        return f(0, n, s, dp)-1;
    }
};

// tabulation code tc = n^3, sc = n
class Solution {
private:
    bool pal(int i, int j, string &str){
        while(i<=j){
            if(str[i] != str[j]) return false;
            i++;
            j--;
        }
        return true;
    }
public:
    int minCut(string s) {
        int n = s.length();
        vector<int>dp(n+1, 0);
        for(int i=n-1; i>=0; i--){
            int mincost = INT_MAX;
            for(int j=i; j<n; j++){
                if(pal(i, j, s)){
                    int cost = 1 + dp[j+1];
                    mincost = min(mincost, cost);
                }
            }
            dp[i] = mincost;
        }
        return dp[0]-1;
    }
};
