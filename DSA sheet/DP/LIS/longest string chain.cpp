// code
class Solution {
    static bool comp(string &s1, string &s2){
        if(s1.length()<s2.length()) return true;
        return false;
    }
public:
    bool compare(string &s1, string &s2){
        int i=0, j=0;
        while(i<s1.length() && j<s2.length()){
            
            if(s1[i]==s2[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
            
        }
        if(j==s2.length()) return true;
        return false;
    }

    
    int longestStrChain(vector<string>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end(), comp);
        vector<int>dp(n, 1), hash(n);
        int maxi = 1;

        // as minimum chain is of length 1
        for(int i=1; i<n; i++){
            hash[i] = i;
            for(int prev=0; prev<i; prev++){
                if(arr[prev].length()+1 == arr[i].length() && compare(arr[i], arr[prev]) && 1+dp[prev]>dp[i]){
                    dp[i] = 1 + dp[prev];
                    maxi = max(dp[i], maxi);
                }
            }
        }
        return maxi; 
    }
};

// tc = nlogn + n^2*length 
// sc = nlogn sorting + n dp array
