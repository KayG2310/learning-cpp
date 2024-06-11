#include <bits/stdc++.h>
using namespace std;

int binocoeff(int n, int k){
    // creating pascal's triangle
    vector<vector<int>>table(n+1, vector<int>(k+1,0));
    // 0 to n rows = n+1 , initializing all as 0
    for(int i=0; i<=n;i++){
        for(int j=0; j<=min(i,k);j++){
            // base case
            if(j==0 || j==i){
                table[i][j] = 1;
            }
            else {
                table[i][j] = table[i-1][j-1]+table[i-1][j];
            }
        }
    }
    return table[n][k];
}
int main() {
   cout<<binocoeff(5,2);
}
