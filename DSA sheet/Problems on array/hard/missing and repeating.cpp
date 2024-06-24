// brute force techniqu e
#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {4,2,3,6,1,1};
    int n = sizeof(arr)/sizeof(int);
    
    // brute force
    // create a frequency map
    unordered_map<int,int>freq;
    for(int i=0; i<n; i++){
        freq[arr[i]]++;
    }
    
    for(int i=1; i<=n;i++){
        if(freq.find(i) == freq.end()){
            cout<<"missing: "<<i<<endl;
        }
        if(freq[i]==2){
            cout<<"repeating: "<<i<<endl;
        }
    }
}

// better technique ---> hashing
#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {4,2,3,6,1,1};
    int n = sizeof(arr)/sizeof(int);
    
    vector<int>hash(n+1,0);
    
    for(int i=0; i<n;i++){
        hash[arr[i]]++;
    }
    for(int i=1; i<n+1; i++){
        if(hash[i]==2){
            cout<<"repeating: "<<i<<endl;
        }
        if(hash[i]==0){
            cout<<"missing: "<<i<<endl;
        }
    }
}

// optimal approach ---> using math O(n)
#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {4,2,2,3,6,1};
    int n = sizeof(arr)/sizeof(int);
    
    int linear=0;
    int square = 0;
    
    
    for(int i=0; i<n;i++){
        linear+=arr[i];
        square+=(arr[i]*arr[i]);
    }
    
    int xminusy = linear - ((n*(n+1))/2);
    int xsqminusysq = square - ((n*(n+1)*(2*n+1))/6);
    int xplusy = xsqminusysq/xminusy;
    
    cout<<"repeating: "<<(xminusy+xplusy)/2<<endl;
    cout<<"missing: "<<(xplusy-xminusy)/2;
    
}
