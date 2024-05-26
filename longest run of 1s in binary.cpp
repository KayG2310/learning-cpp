#include<bits/stdc++.h>
using namespace std;

int solve(int n) {
    set<int>v;
    int length = 0;
    while(n>0){
        int lastbit = n&1;
        n = n>>1;
        if(lastbit==1){
            length++;
        } 
        else {
            
                v.insert(length);
                length = 0;
            
        }
        v.insert(length);
    }
    return *max_element(v.begin(), v.end());
}
