// memoized code --> m*n + m*n + n

#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int f(int index, vector<int>& arr, int target, vector<vector<int>>&dp){
        if(target==0) return 1;
		if(index==0) return arr[index]==target;
        if(dp[index][target] != -1) return dp[index][target];
        int notpick = f(index-1, arr, target, dp)%mod;
        int pick = 0;
        if(arr[index]<=target) pick = f(index-1, arr, target-arr[index],dp)%mod;
        return dp[index][target] = (pick+notpick)%mod;
    }
int findWays(vector<int>& arr, int target)
{
	// Write your code here.
	int n = arr.size();
	vector<vector<int>>dp(n, vector<int>(target+1, -1));
	sort(arr.begin(), arr.end(), greater<int>());
	return f(n-1, arr, target, dp)%mod;
}

// tabulation 

#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int findWays(vector<int>& arr, int target)
{
	// Write your code here.
	int n = arr.size();
	vector<vector<int>>dp(n, vector<int>(target+1, 0));
	sort(arr.begin(), arr.end(), greater<int>());
	for(int i=0; i<n; i++){
		dp[i][0]= 1;
	}
	if(arr[0]<=target) dp[0][arr[0]]=1;
	for(int i=1; i<n; i++){
		for(int j=0; j<=target; j++){
			int notpick = dp[i-1][j]%mod;
			int pick = 0;
			if(arr[i]<=j) pick = dp[i-1][j-arr[i]]%mod;
			dp[i][j] = (pick+notpick)%mod;
		}
	}
	return dp[n-1][target]%mod;
} 

// space opt 

#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int findWays(vector<int>& arr, int target)
{
	// Write your code here.
	int n = arr.size();
	vector<vector<int>>dp(n, vector<int>(target+1, 0));
	vector<int>prev(target+1, 0);
	vector<int>cur(target+1, 0);
	sort(arr.begin(), arr.end(), greater<int>());
	
	prev[0]= 1;
	cur[0] = 1;

	
	if(arr[0]<=target) prev[arr[0]]=1;
	for(int i=1; i<n; i++){
		for(int j=0; j<=target; j++){
			int notpick = prev[j]%mod;
			int pick = 0;
			if(arr[i]<=j) pick = prev[j-arr[i]]%mod;
			cur[j] = (pick+notpick)%mod;
		}
		prev = cur;
	}
	return prev[target]%mod;
} 
