#include<bits/stdc++.h>
using namespace std;
// not valid if size of string is very large due to huge time complexity
int main() {
    /* given N strings, print unique strings in lexographical order
    with their frequency 
    N <= 10^5
    |S| <=100 size of string less than 100
    */
    map<string,int>m; 
    // logic : given that strings must be unique so they are keys and frequency is a number
    int N;
    cin>>N;
    for(int i =0; i<N;i++){
        string s;
        cin>>s;
        if(m[s]==0){
            m[s]=1;
        } else{
            m[s]+=1;
        }
    }
    // alternatively one can avoid if loop and do m[s]++;
    
    for(auto it= m.begin(); it!=m.end(); it++){
        cout<<it->first<<" frequency: "<< it->second<<endl;
    }
    return 0;
}
