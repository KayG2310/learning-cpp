#include<bits/stdc++.h>
using namespace std;

int main() {
    /*you are given two 32 bit numbers
    N and M and two bit positions i and j
    write a method to set all bits between
    i and j in N equal to M
    M (becomes a substring of N locationed at and starting at j)
    */
    // example 
    // N = 10000000000
    // M = 10101
    // i = 2, j = 6
    // output = 10001010100
    /*
    approach :- we first clear the bits from j to i
    */
    int M,N,j,i;
    cin>>M>>N>>j>>i;
    int mask1 = (~0)<<j+1;
    int mask2 = (1<<i)-1;
    N = N&(mask1 | mask2);
    // we have cleared those bits
    
    // now we update those bits
    // we left shift M by i places
    M = M<<i;
    N = N | M;
    cout<<N;
    
    
}
