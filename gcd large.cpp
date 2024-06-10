#include<bits/stdc++.h>
using namespace std;

int chartonum(char c){
    return c-'0';
}
int gcd(int a, int b){
    if(b==0) return a;
    else return gcd(b,a%b);
}
int solve(int a, string b){
    int n=chartonum(b[0]);
    for(int i=0;i<b.length()-1;i++){
        n=n%a;
        n=n*10+b[i+1];
    }
    n=n%a;
    return gcd(a,n);
}
