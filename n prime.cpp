#include<bits/stdc++.h>
using namespace std;

int main(){
    // checking if a number is prime - 2 methods
    int n;
    cin>>n;
    int num=2;
    while(n){
        
        int div=0;
        for(int i=2; i<num; i++){
            if(num%i==0){
                div++;
            }
        }
        if(div==0){
            cout<<num<<" ";
            n--;
        }
        num++;
        
    }
    cout<<endl;
    // method 2
    int m;
    cin>>m;
    int k =2;
    while(m){
        
        int divi=0;
        for(int i=2; i<=pow(k,0.5); i++){
            if(k%i==0){
                divi++;
            }
        }
        if(divi==0){
            cout<<k<<" ";
            m--;
        }
        k++;
        
    }
    
}
