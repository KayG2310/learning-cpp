#include<bits/stdc++.h>
using namespace std;
const int P = 5;
cont int N = 1e5;
long long fact[N];
int mult(int x, int y){
    return (x*y)%P;
    // int has to mean long long int
}
int divm(int x, int y){
    return mult(x, pow(y,P-2));
}
void calculate_fact(){
    fact[0] = 1;
    for(int i=1; i<N; i++){
        fact[i] = mult(fact[i-1],i);
    }
}
int main(){
    // talking about remainders of negative numbers
    // (-1 % 5) = 4 as per congruency
    // for multiplication use long long
    cout<<divm(50,2);
    // for ncr you can use combo of factorial, multiplication and factorial
}
