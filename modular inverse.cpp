#include<bits/stdc++.h>
using namespace std;
// multiplicative modulo inverse
vector<int> extended(int a, int b){
    // returns {x,y}
    if(b==0){
        // return x,y
        return {1,0};
    }
    vector<int>result = extended(b, a%b);
    int smallx = result[0];
    int smally = result[1];
    
    int x = smally;
    int y = smallx - (a/b)*smally;
    return {x,y};
}
int mmi(int a, int m){
    vector<int>result = extended(a,m);
    int x = result[0];
    int y = result[1];
    int gcd = (a*x)+(m*y);
    if(gcd==1){
        return (x%m + m)%m;
    }
    return -1;
    
}
int main() {
    int a,m;
    cin>>a>>m;
    
}
