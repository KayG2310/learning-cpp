#include<bits/stdc++.h>
using namespace std;
const int P = 5;
int sub(int x, int y){
    return ((x-y)%P + P)%P;
}
int main(){
    // talking about remainders of negative numbers
    // (-1 % 5) = 4 as per congruency
    // for multiplication use long long
    cout<<sub(-3,5);
}
