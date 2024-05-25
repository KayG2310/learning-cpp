#include<bits/stdc++.h>
using namespace std;

int main() {
    int x,i;
    cin>>x>>i;
    // we can set mask to negative zero and do left shift by i places
    // then take and
    int mask = (~0)<<i;
    x = x&mask;
    cout<<x;
}
