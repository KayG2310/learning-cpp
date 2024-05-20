#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int ar[n];
    for(int i=0; i<n; i++){
        cin>>ar[i];
    }
    sort(ar.begin(),ar.end());
    // ar is the beginning pointer in itself, ar+n will give the n-1 +1th pointer
    for(int j=0; j<n; j++){
        cout<<ar[j]<< "---->";
    }
    
    
}
// introsort technique
