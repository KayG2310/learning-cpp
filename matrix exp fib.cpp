#include<bits/stdc++.h>
using namespace std;

int fib(long long n){
    // we need fixed matrices of size 2
    
}
struct mat{
    int m[2][2];
    mat() {
        memset(m,0,sizeof(m));
    }
    void identity(){
        for(int i=0;i<2;i++){
            m[2][2] = 1;
        }
    }
}

int main(){
    cout<<solve(7,3);
}
