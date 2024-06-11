#include<bits/stdc++.h>
using namespace std;
const int P = 5;
int mult(int x, int y){
    return (x*y)%P;
    // int has to mean long long int
}
int divm(int x, int y){
    return mult(x, pow(y,P-2));
}

int main(){
    // talking about remainders of negative numbers
    // (-1 % 5) = 4 as per congruency
    // for multiplication use long long
    cout<<divm(50,2);
}
