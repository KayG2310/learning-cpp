#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0; i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    int n2;
    cin>>n2;
    
    // lower bound
    
    int *pt = lower_bound(a,a+n, n2 );
    if(pt == a+n){
        cout<<"Does not exist";
    } 
    else{
        cout<<(*pt);
    }
    
    // upper bound
    int *pt2 = upper_bound(a,a+n, n2 );
    cout<<(*pt2);
    
}
