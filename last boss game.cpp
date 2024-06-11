#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int h,n;
        cin>>h>>n;
        vector<int>damage(n);
        for(int i=0; i<n;i++){
            cin>>damage[i];
        }
        // damage contains ai's
        vector<int>cool(n);
        for(int i=0; i<n;i++){
            cin>>cool[i];
        }
        // cool contains each cooldown
        int turns = 0;
        int att = sum(damage.begin();damage.end());
        while(h){
            // here we start decreasing the health
            turns++;
            if(att>=h){
                
                break;
            }
            else{
                h = h-att;
            }
            for(int i=0; i<n;i++){
                if(turns = turns-1+cool[i])
            }
        }
    }
}
