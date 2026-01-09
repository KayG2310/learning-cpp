// optimal for only positives
#include<bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {1,2,3,1,1,1,1,4,2,3};
    int k = 5;
    int left =0, right = 0;
    long long sum = arr[0]
    ;
    // sum = 1
    int maxlen = 0;
    int n = sizeof(arr)/sizeof(int);
    while(right<n){
        while(left<=right && sum>k){
        sum -= arr[left];
        left++
        }
        if(sum==k){
            maxlen = max(maxlen, right-left);
        }
        right++;
        if(right< n){
            sum+=arr[right];
        }
    }
    cout<<maxlen;
    
}

/*
if(sum<k){
            right++;
            sum+=arr[right];
        } */
