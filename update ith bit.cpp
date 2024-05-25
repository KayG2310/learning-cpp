#include<bits/stdc++.h>
using namespace std;

int main() {
    int x,i;
    cin>>x>>i;
    int v;
    cin>>v;
    // this time we need to do an OR operation
    // combo of set & clear
    
    int mask = ~(1<<i);
    x = x & mask; // clearing the ith bit
    
    int mask2 = (v<<i);
    // v could be zero and one
    x = x|mask2 ;
    cout<<x;
    
}
