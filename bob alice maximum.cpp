#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v(n);
        vector<int>m(n-1);
        for(int i=0; i<n; i++){
            cin>>v[i];
        }
        for(int i=0; i<n-1; i++){
            m[i] = max(v[i],v[i+1]); 
        }
        
        int m2 = *min_element(m.begin(), m.end());
        cout<<m2-1<<endl;
    }
}
