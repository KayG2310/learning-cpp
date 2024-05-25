#include<bits/stdc++.h>
using namespace std;

int main() {
    int x,i;
    cin>>x>>i;
    // this time we need to do an OR operation
    int mask = (1<<i);
    x = x | mask;
    cout<<x;
}
