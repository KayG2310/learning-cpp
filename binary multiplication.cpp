#include<bits/stdc++.h>
using namespace std;

int main(){
    // eg = find (a*b)%c a,b,c<=10^15 
    long long a,b,c;
    cin>>a>>b>>c;
    long long result = 0; // we are doing addition here
    // dry run
    // eg a = 3, b= 7 = 111
    // if, r = 3, a=6, b = 011
    // if, r = 9, a = 12, b=001
    //if, r = 21, a=24, b=000 stops
    while(b){
        // since we are adding a to itself b times
        if(b&1==1){
            result = (result +a)%c;
        }
        a = (a+a)%c;
        b=b>>1;
    }
    
}
