#include<bits/stdc++.h>
using namespace std;

int main() {
    int x,i;
    cin>>x>>i;
    int mask = (1<<i); // left shift by i places
    if(x&mask){
        cout<<1;
    } else{ cout<< 0;}
}
