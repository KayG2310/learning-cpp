#include<bits/stdc++.h>
using namespace std;
// extended euclidean code
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

int main() {
    int a,b;
    cin>>a>>b;
    int x,y;
    vector<int>ans = extended(a,b);
    // we need to find ax + by = gcd(a,b)
    cout<<ans[0]<<" & "<<ans[1];
    
}
