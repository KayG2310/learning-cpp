// basic recursive code pick not pick 2^n 
#include <bits/stdc++.h> 
int f(int index, vector<int> weight, vector<int> value, int n, int maxWeight){
	if(index==n) return 0;
	int pick = INT_MIN;
	if(weight[index]<= maxWeight){
		pick = value[index]+f(index+1, weight, value, n, maxWeight - weight[index]);
	}
	int notpick = f(index+1, weight, value, n, maxWeight);
	return max(pick, notpick);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	return f(0, weight, value, n, maxWeight);
}

//------------------------------------------------------------------------------------------------------------------

// memoized code (my version)
#include <bits/stdc++.h> 
int f(int index, vector<int> weight, vector<int> value, int n, int maxWeight,
vector<vector<int>>&dp){
	if(index==n) return 0;
	if(dp[index][maxWeight] != -1) return dp[index][maxWeight];
	int pick = INT_MIN;
	if(weight[index]<= maxWeight){
		pick = value[index]+f(index+1, weight, value, n, maxWeight - weight[index], dp);
	}
	int notpick = f(index+1, weight, value, n, maxWeight, dp);
	return dp[index][maxWeight] = max(pick, notpick);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>>dp(n, vector<int>(maxWeight+1,-1));
	return f(0, weight, value, n, maxWeight,dp);
} 
//------------------------------------------------------------------------------------------------------------------

// tabulation code, tc = n*w, sc = n*w
#include <bits/stdc++.h> 
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
    vector<vector<int>> dp(n+1, vector<int>(maxWeight + 1, 0));
		for(int i=n-1; i>=0; i--){
			for(int w=0; w<=maxWeight; w++){
				int pick = INT_MIN;
				if(weight[i]<= w){
					pick = value[i]+dp[i+1][w-weight[i]];
				}
				int notpick = dp[i+1][w];
				dp[i][w] = max(pick, notpick);
			}

		}
        return dp[0][maxWeight];
}

// space optimized
#include <bits/stdc++.h> 
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
        vector<int>next(maxWeight+1,0), cur(maxWeight+1, 0);
		for(int i=n-1; i>=0; i--){
			for(int w=0; w<=maxWeight; w++){
				int pick = INT_MIN;
				if(weight[i]<= w){
					pick = value[i]+next[w-weight[i]];
				}
				int notpick = next[w];
				cur[w] = max(pick, notpick);
			}
			next = cur;

		}
        return next[maxWeight];
}

//------------------------------------------------------------------------------------------------------------------

//                                                       STRIVER CODE 

//------------------------------------------------------------------------------------------------------------------

// recursive to single element narrowing down (opposite from what I wrote index wise)
#include <bits/stdc++.h> 
int f(int index, vector<int> weight, vector<int> value, int maxWeight){
	if(index==0){
		if(weight[0]<= maxWeight){
			return value[0];
		}
		else return 0;
	}
	int pick = INT_MIN;
	if(maxWeight-weight[index]>=0){
		pick = value[index]+f(index-1, weight, value, maxWeight - weight[index]);
	}
	int notpick = f(index-1, weight, value, maxWeight);
	return max(pick, notpick);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight){
	return f(n-1, weight, value, maxWeight);
}

//------------------------------------------------------------------------------------------------------------------
// memoised striver code
// recursive to single element narrowing down (opposite from what I wrote index wise)
#include <bits/stdc++.h> 
int f(int index, vector<int> weight, vector<int> value, int maxWeight, vector<vector<int>>&dp){
	if(index==0){
		if(weight[0]<= maxWeight){
			return value[0];
		}
		else return 0;
	}
	if(dp[index][maxWeight] != -1) return dp[index][maxWeight];
	int pick = INT_MIN;
	if(maxWeight-weight[index]>=0){
		pick = value[index]+f(index-1, weight, value, maxWeight - weight[index], dp);
	}
	int notpick = f(index-1, weight, value, maxWeight, dp);
	return dp[index][maxWeight] = max(pick, notpick);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight){
	vector<vector<int>>dp(n, vector<int>(maxWeight+1, -1));
	return f(n-1, weight, value, maxWeight, dp);
}

//------------------------------------------------------------------------------------------------------------------


  
