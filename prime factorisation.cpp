// not so brute force
#include<bits/stdc++.h>
using namespace std;


int main(){
    int N;
    cin>>N;
    // n is the number whose prime factorisation is to be found
    for(int i=2; i<=N; i++){
        int c = 0;
        if(N%i==0){
            // if i divides N
            while(N%i==0){
                c++;
                N/=i;
            }
            cout<<i<<" "<<c;
            cout<<endl;
        }
        
    }
}
