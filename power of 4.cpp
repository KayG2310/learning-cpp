#include<bits/stdc++.h>
using namespace std;

bool check4(int N){
    int mask;
    int position = log(N)/log(4); // gives 4-> 1, 16->2
    mask = N>>(2*position);
    
    if(mask==1){
        if(position==0){
            return false;}
            
        return true;
        
    }else{return false;}
}


int main() {
    // to check if a number inputted is a power of 4 or not
    // power of 4 looks like 1 on even indices and others zero
    // we could check if 1 shifted to even places gives and & gives the number itself
    // one way to right shift the leading 1 to see if it becomes one.
    // their and = 0
    int N;
    cin>>N
    ;
    cout<<check4(N);
    
    
}
