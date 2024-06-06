#include<bits/stdc++.h>
using namespace std;

int main(){
    // total divisors till N code
    int n;
    cin>>n;
    vector<int>primes = {2,3,5,7,11,13,17,19,23,29}; // first ten primes
    // we generate all subsets of these prime numbers
    // using binary method
    int k = primes.size();
    int ans = 0;
    for(int i=1; i<(1<<k); i++){
        int lcm = 1;
        for(int j=0; j<k; j++){
            // if ith bit of jth element is set
            if((i>>j)&1){
            //cout<<primes[j]<<" ";
            lcm*=primes[j];
            }
        }
        cout<<endl;
        if(__builtin_popcount(i)%2==0){
            ans-=(n/lcm);
        }
        else{
            ans+=(n/lcm);
        }
    }
    
}
