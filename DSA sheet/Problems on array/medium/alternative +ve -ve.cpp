// brute force - make a positive array, make a negative array, you can replace in place sc = O(N) TC = O(2N)
// we cannot reduce the extra space
#include<bits/stdc++.h>
using namespace std;

int main() {
    int arr[6] = {-7,-1,-5,3,6,4};
    int n = sizeof(arr)/sizeof(int);
    int ans[6];
    int pos=0, neg = 1;
    for(int i=0; i<n;i++){
        if(arr[i]>0){
            ans[pos] = arr[i];
            pos+=2;
        }
        else {
            ans[neg] = arr[i];
            neg+=2;
        }
    }
    
    for(int i=0; i<n;i++){
        cout<<ans[i]<<" ";
    }
    
}
/*
tc = O(N), sc = O(N)
*/

//variety 2 --> if extra elements of same parity left add them to beginning
// here brute force solution can't work because that relied on the fact that positive and negative numbers are same
