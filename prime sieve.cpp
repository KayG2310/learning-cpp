#include<bits/stdc++.h>
using namespace std;


int main(){
    int N;
    cin>>N;
    vector<int> primes;
    for(int i=1; i<=N;i++){
        primes.push_back(i);
    }
    sort(primes.begin(), primes.end());
    // create a list
    primes[0]=0; // 1 and 0 are not prime
    for(long long i=1; i<=N;i++){
        if(primes[i]){
            for(long long j = i*i; j<=N;j=j+1){
                prime[j]=0;
            }
        }
            
        }
    
    
    
}
