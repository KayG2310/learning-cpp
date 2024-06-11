#include<bits/stdc++.h>
using namespace std;
cont int n=1e5;
int main(){
    int x;
    // create a sieve first;
    vector<bool>pr(n,true);
    for(int i=2; i<n;i++){
        for(int j=i*i; j<n; j+=i){
            pr[j] = false;
        }
    }
    
    vector<int> tot(n);
    iota(tot.begin(), tot.end(),0);
    // to fill the specified range with some value
    for(int i=2;i<n;i++){
        if(pr[i]==true){
            for(int j=i; j<n;j+=i){
                tot[j]/=i;
                tot[j] *= (i-1);
                
            }
        }
    }
    
}
