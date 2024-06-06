#include<bits/stdc++.h>
using namespace std;

int countPrimes(int n){
    int count;
    for(int i=2; i<n;i++){
        int c=0;
        for(int j=2; j<i; j++){
            if(i%j==0){
                c++;
                break;
            }
        }
        if(c==0){
            count++;
        }
    }
    return count;
}
int main(){
    int n;
    cin>>n;
    cout<<countPrimes(n);
}

/*

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int countPrimes(int n){
    if(n==0) {
        return 0;
    }
    vector <int> prmSieve(n,1);
    prmSieve[0]=prmSieve[1]=0;
    for(ll i=2;i<n;i++){
        if(prmSieve[i]){
            for(ll j=i*i;j<n;j+=i){
                prmSieve[j]=0;
            }
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        if(prmSieve[i]) cnt++;
    }
    return cnt;
}*/
