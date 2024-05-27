#include<bits/stdc++.h>
using namespace std;

int tsp(vector<vector<int>> distance, int Setofcities,int position, int nodes){
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
    int ans = INT_MAX;
    //otherwise try all
    // checking if a city is visited by checking if its indexth byte is 1
    for(int choice=0; choice<n; choice++){
        if(Setofcities & (1<<choice)==0){
            int subprob = dist[pos][choice] + tsp(dist, Setofcities | (1<<choice), choice,n);
            ans = min(ans, subprob);
        }
    }
    return ans;
    
    
}

int main(){
    
}
