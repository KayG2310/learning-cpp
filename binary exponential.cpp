#include<bits/stdc++.h>
using namespace std;
int main() {
    int a,b;
    cin>>a>>b;
    int result = 1;
    // eg 2^5
    // b= 5, goes into while loop
    while(b){
        // checking if last bit is a set bit or not
        // b = 101
        // goes to if,result = 2*1 = 2, a = 4
        // b = 010
        // goes to else, a = 16
        // b = 001
        // if, result = 16*2 = 32
        // b=0 out of the loop
        if(b&1==1){
            result = a*result;
           
        }
        
              a *=a;
        
      
        b=b>>1;
    }
    cout<<result;
}
