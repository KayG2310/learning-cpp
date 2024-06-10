#include<bits/stdc++.h>
using namespace std;
int gcd2(vector<int> &s) {
    int g = s[0];
    for (int i = 1; i < s.size(); i++) {
        g = gcd(g, s[i]);
        if (g == 1) {
            return 1; // Early exit if GCD is 1
        }
    }
    return g;
}

int gcd(int s, int k){
    if(s<k){
        swap(s,k);
    }
    if(k==0){
        return s;
    }
    else{
        return gcd(k,s%k);
    }
}
vector<int>solve(int n,int m, vector<int> a, vector<int> b){
    vector<int>ans(m);
    for(int j=0;j<m;j++){ 
        // m(n + n*logn
        // we have J's
        // we take b j
        int bj = b[j];
        vector<int>temp(n);
        for(int i=0; i<n;i++){
            temp[i] = a[i] + b[j];
        }
    // we have a temporary array
    ans[j] = gcd2(temp);
    }
    return ans;
}

int main() {
    int n= 4, m= 4;
    vector<int>a= {1, 25, 121, 169};
    vector<int>b= {1, 2, 7, 23};
    vector<int> c = solve(n,m,a,b);
    for(int i=0; i< c.size(); i++){
        cout<<c[i]<<" ";
    }
}
