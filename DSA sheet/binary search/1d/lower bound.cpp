#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[] = {3,4,6,7,9,12,14,16,17};
    int n = sizeof(arr)/sizeof(int);
    
    int target = 13;
    int low=0, high = n-1;
    int mid = 0;
    int ans = n; // assuming it DNE
   
    while(low<=high){
        mid = (low+high)/2;
        if(arr[mid]>=target){
            ans = min(ans, mid);
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    cout<<ans;
}

// this code is the same for finding the insert position
