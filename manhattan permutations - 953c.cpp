#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>ans(n);
        if(k%2!=0){
            cout<<"no"<<endl;
            break;
        }
        else {
            for(int i=n; i>=1;i--){
                if(k>=2*(i-1)){
                    for(int j = i; j>=1;j--){
                        ans[abs(j-i)] = j;
                    }
                }
                
            }
        }
}
}
// n = 3, sum = 4
// n = 3, 4>=4; accepted; 3 2 1

// n = 7, sum = 0
// n = 7, 0 not >=12 
    // n =6, no
    // n = 5, no
    // n =4, no
    // n=3, no
    // n=2,no
    // n=1, done
