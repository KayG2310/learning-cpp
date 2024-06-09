// algo is called segmented sieve if the range numbers are too big
#include<bits/stdc++.h>
using namespace std;
#define n 100000
int sievearr[n+1] = {0};
vector<int>primes;
void sieve(){
    for(long long i=2; i<=n;i++){
        if(sieve[i]==0){
            primes.push_back(i);
            // mark the multiples of i as non-prime
            for(long long j=i*i;j<=n;j+=i){
                sievear[j]=1;
                // number is not prime
            }
        }
    }
} 
// indices with value 0 are prime, 1 are not prime

int main() {
    sieve();
    // precomputed the prime numbers
    int t;
    cin>>t;
    while(t--){
        int leftrange,rightrange;
        cin>>leftrange>>rightrange;
        // this is the segment of our sieve
        // here leftrange will be shifted to 0 and rightrange to right - left
        vector<int>segment(rightrange-leftrange+1,0);
        // everything initially thought to be 0
        for(int p:primes){
            // stop when p^2 > rightrange
            if(p*p>rightrange){
                break;
            }
            
            // otherwise we need to find the nearest starting point
            int start = (leftrange/p)*p;
            if(p>=leftrange && p<=rightrange){
                start = 2*p;
            }
            for(int j=start; j<=rightrange; j+=p){
                if(j<leftrange){
                    continue;
                }
                //non prime
                segment[j-leftrange] = 1;
                
            }
        }
        
        // after this all primes will be marked as 0
        for(int i=leftrange; i<=rightrange;i++){
            if(segment[i-leftrange]==0 && i!=1){
                cout<<i<<endl;
            }
        }
        
    }
    return 0;
}
