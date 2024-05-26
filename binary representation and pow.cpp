#include<bits/stdc++.h>
using namespace std;


int main() {
// make binary representation of a number 
// eg = 7 = 111
// = 10^ 0 + 10^1 + 10^2 = 100+10+1 = 111
int n;
cin>>n;
int ans = 0;
// we have to keep removing the last bit
int i = 0;
while(n){
    int lastbit= (n&1);
    // in this case last bit = 1
    ans += lastbit*pow(10,i);
    i++;
    n = n>>1;
}
cout<<ans;
}
