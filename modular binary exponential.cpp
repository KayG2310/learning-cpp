#include<bits/stdc++.h>
using namespace std;
int main() {
    const long long mod = 1e9 + 7;
    long long a,b;
    cin>>a>>b;
    long long result1 = 1;
  
    while(b){
        if(b&1==1){
            result1 = a*result1;
            result1 %= mod;
        }
        a *=a;
        a = a%mod;
 
        b=b>>1;
    }
    cout<<result1;
}
// this code gives 2^200 % mod
