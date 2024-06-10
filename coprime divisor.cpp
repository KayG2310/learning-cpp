/* sana's 

  #include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    else return gcd(b,a%b);
}

int solve(int a,int b){
    int n = 1;// a = nx;
    while(1){
        if(a % n == 0){
            if(gcd(a/n, b) == 1){
                break;
            }
        }
        n++;
    }
    return a/n;
} */ 
// above is a good solution
#include<bits/stdc++.h>
using namespace std;
int gcd(int s, int k){
    if(s<k){
        swap(s,k);
    }
    if(k==0){
        return s;
    }
    else{
        return gcd(k,s%k);
    }
}
int solve(int a,int b){
    
    vector<int>divisors;
    for(int i=pow(a,0.5); i>=1;i--){
        if(a%i==0){
            divisors.push_back(i);
            divisors.push_back(a/i);
        }
    }
    // we have divisors
    sort(divisors.begin(), divisors.end());
    auto it = divisors.end();
    it--;
    while(it!=divisors.begin()){
        if(gcd(*it, b)==1){
            return *it;
        }
        it--;
    }
    return -1;
}


