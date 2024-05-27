#include<bits/stdc++.h>
using namespace std;

int tsp(vector<vector<int>> distance, int Setofcities,int position, int nodes, vector<vector<int>>&dp){
    // representing tree/graph with nested vector
    // let's say D C B A = 0 0 0 0
    // if A is travelled it becomes 0 0 0 1
    // B it becomes 0 0 1 1
    // c d it is 1111
    
    // base case
    if(setofcities == (1<<n)-1){
        // return the cose from the current city to source
        return distance[pos][0];
    }
    if(dp[Setofcities][pos]!=1){
        //not visited
        return dp[Setofcities][pos];
    }
    int ans = INT_MAX;
    //otherwise try all
    // checking if a city is visited by checking if its indexth byte is 1
    for(int choice=0; choice<n; choice++){
        if(Setofcities & (1<<choice)==0){
            int subprob = dist[pos][choice] + tsp(dist, Setofcities | (1<<choice), choice,n,dp);
            ans = min(ans, subprob);
        }
    }
    dp[Setofcities][pos] = ans;
    return ans;
    
    
}

int main(){
    vector<vector<int>> dp(1<<n, vector<int>(n,-1));
    cout<<tsp(distance,1,0,n,dp);
}
