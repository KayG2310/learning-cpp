// printing ncr 
#include<bits/stdc++.h>
using namespace std;

int main(){
    // pascal's triangle
    int n, r;
    cin>>n>>r;
    int p=1;
    for(int i=0; i<r; i++){
        p *= (n-i);
        p /= (i+1);
    }
    
    // p = 1*(10/1)*(9/2)*(8/3)
    cout<<p;
}

// printing nth row entirely 
#include<bits/stdc++.h>
using namespace std;

long long ncr(int n, int r){
    int p=1;
    if(n==r || r==0) return 1;
    for(int i=0; i<r; i++){
        p *= (n-i);
        p /= (i+1);
    }
    
    // p = 1*(10/1)*(9/2)*(8/3)
    return p;
}
int main(){
    // pascal's triangle
    int n;
    cin>>n;
    for(int i=0; i<n;i++){
        cout<<ncr(n-1,i)<<" ";
    }
}

// printing till n rows
class Solution {
public:
    long long ncr(int n, int r){
        int p=1;
        if(n==r || r==0) return 1;
        for(int i=0; i<r; i++){
            p *= (n-i);
            p /= (i+1);
        }
        
        // p = 1*(10/1)*(9/2)*(8/3)
        return p;
    }

    // end of function 1


    vector<vector<int>> generate(int n) {
        
        vector<vector<int>> ans(n);
        for(int i=0; i<n;i++){ // runs for n rows
            vector<int>minians(i+1); // 
            for(int j=0; j<i+1;j++){
                minians[j] = ncr(i,j);
            }
            ans[i] = minians;
        }
        return ans;

    }
};
