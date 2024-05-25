#include<bits/stdc++.h>
using namespace std;

int main() {
    int x,i;
    cin>>x>>i;
int mask = ~(1<<i);
x = x&mask;
cout<<x;
}
