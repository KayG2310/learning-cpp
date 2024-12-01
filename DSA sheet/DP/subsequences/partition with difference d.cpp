// basic recursion (2^n) 
#include <bits/stdc++.h> 
int f(int index, vector<int>& arr, int k){
        if(k == 0) return 1;
        if(index==0) return arr[0]==k;
        int notpick = f(index-1, arr, k);
        int pick = 0;
        if(arr[index]<=k) pick = f(index-1, arr, k-arr[index]);
        return pick+notpick;
    }
int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int total =0;
        // int n = arr.size();
        for(int i=0; i<n; i++){
            total += arr[i];
        }
        int k = (total-d)/2;
        if((total-d)%2 || k<0) return 0;
        sort(arr.begin(), arr.end(), greater<int>());
        return f(n-1, arr, k);
}


// memoized/ tabulation 
#include <bits/stdc++.h> 
const int mod = 1e9+7;
int countPartitions(int n, int d, vector<int> &num) {
    int totSum = 0;
    for(int i=0; i<n;i++){
        totSum += num[i];
    }
    int tar = (totSum-d)/2;
    //Checking for edge cases
    if(totSum-d <0 || (totSum-d)%2 ) return 0;
    vector<vector<int>> dp(n,vector<int>(tar+1,0));
    
    if(num[0] == 0) dp[0][0] =2;  // 2 cases -pick and not pick
    else dp[0][0] = 1;  // 1 case - not pick
    
    if(num[0]!=0 && num[0]<=tar) dp[0][num[0]] = 1;  // 1 case -pick
    
    for(int ind = 1; ind<n; ind++){
        for(int target= 0; target<=tar; target++){
            
            int notTaken = dp[ind-1][target];
    
            int taken = 0;
                if(num[ind]<=target)
                    taken = dp[ind-1][target-num[ind]];
        
            dp[ind][target]= (notTaken + taken)%mod;
        }
    }
    return dp[n-1][tar];
}


