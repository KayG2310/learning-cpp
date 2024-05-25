#include<bits/stdc++.h>
using namespace std;

int main() {
    int x,i,j;
    cin>>x>>i>>j;
    // clear range of bits 
    // we set two masks
    // one in which the numbers to the right of the range are 1
    // in another numbers to the left are all 1
    // take and of all 3
    int mask = (~0)<<j+1
    ;
    int mask2 = (1<<i)-1;
    x = x&(mask | mask2);
    cout<<x;
    // or makes the range bits zero
}
