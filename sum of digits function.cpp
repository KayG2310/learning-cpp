#include<bits/stdc++.h>
using namespace std;

int solve(long long A, long long N){
    // sum of digits of a number is number mod 9
    const int mod=9;
    int result = 1;
    if(A==9){return 9;}
    while(N){
        
        if(N&1==1){
            result = (result*A)%mod;
        }
        A = (A*A)%mod;
        N = N>>1;
        
    }
    if(result%9==0){
            return 9;
        }
    return result;
}

int main(){
    cout<<solve(7,3);
}
