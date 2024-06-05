#include<bits/stdc++.h>
using namespace std;

int locker(int n){
    long long initial = 1;
    const int mod = 1e9+7;
    
    while(n){
        if(n==1){ return initial; n-=1;}
        // while we have n meters of rope 
        // 5 is broken into 2s and 3s
        // eg 4 - goes to second if 2*2 = 4
        if(n%3==0){
            while(n){
                initial*=3;
                initial%=mod;
                n-=3;
                n%=mod;
            }
        }
        if(n%2==0){
            while(n){
                initial*=2;
                initial%=mod;
                n-=2;
                n%=mod;
            }
        }
        
        if(n%3==1 && n!=1){
            while(n%3==1 && n!=1){
            initial*=3;
            initial%=mod;
            n-=3;
            n%=mod;
            }
        }
        
        if(n%3==2 && n!=2){
            while(n%3==2 && n!=2){
                initial*=3;
                initial%=mod;
                n-=3;
                n%=mod;
            }
        }
        
    }
    return initial;
    
}
int main() {
    int n;
    cin>>n;
    cout<<locker(n);
    return 0;
}
