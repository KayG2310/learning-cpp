// brute force, q different from leetcode
#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[9] = {10, 22, 24,20, 3,4,5,6,11};
    int n = sizeof(arr)/ sizeof(int);
    int maxi = 1;
    int longest = 1;
    for(int i=0; i<n-1; i++){
        if(arr[i]+1==arr[i+1]){
            longest++;
            maxi = longest;
            maxi = max(longest, maxi);
        }
        else{
            longest = 1;
        }
    }
   cout<<maxi;
}
