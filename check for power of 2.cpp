#include<bits/stdc++.h>
using namespace std;

int main() {
    // to check if a number inputted is a power of 2 or not
    // power of 2 looks like 1 0 0 0 0 0 0 
    // n - 1 looks like 0 1 1 1 1 1 1 
    // their and = 0
    int N;
    cin>>N
    ;
    char ans;
    if((N&(N-1))==0){cout<<"yes";} else{cout<<"no";}

    
    
}
