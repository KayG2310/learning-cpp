/* sana's 

  #include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    else return gcd(b,a%b);
}

int solve(int a,int b){
    int n = 1;// a = nx;
    while(1){
        if(a % n == 0){
            if(gcd(a/n, b) == 1){
                break;
            }
        }
        n++;
    }
    return a/n;
} */

