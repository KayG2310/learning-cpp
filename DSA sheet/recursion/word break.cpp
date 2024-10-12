class Solution {
public:
    bool f(int index, unordered_map<char, vector<string>>&m, string &s, vector<int>&dp){
        if(index == s.length()){
            return true;
        }

        if(dp[index] != -1) return dp[index];
        if(m.find(s[index]) == m.end()) return false;
        bool a = false;
        for(string k: m[s[index]]){

            bool flag = true;
            for(int j=1; j<k.length(); j++){
                if(index+j < s.length() && k[j] == s[index+j]) continue;
                else {flag = false; break;}
            }
            if(flag){
                a = a|| f(index+k.length(), m, s, dp);
            }
        }
        return dp[index] = a;
    }
    bool wordBreak(string s, vector<string>& w) {
        unordered_map<char, vector<string>>m;
        for(string val: w){
            m[val[0]].push_back(val);
        }
        vector<int>dp(s.length(), -1);
        return f(0, m, s, dp);

    }
};
