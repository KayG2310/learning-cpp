// brute force - check the right of each element
// nearly O(n2)
#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[5] = {10, 22, 12, 6, 3};
    int n = sizeof(arr)/ sizeof(int);
    for(int i=0; i<n; i++){
        bool leader = true;
        for(int j = i+1; j<n; j++){
            if(arr[j]>arr[i]){
                leader = false;
                break;
            }
        }
        if(leader){
            cout<<arr[i]<<" ";
        }
    }
}

// optimal 

#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[5] = {10, 22, 23, 24, 3};
    int n = sizeof(arr)/ sizeof(int);
    int maxi = INT_MIN;
    vector<int>ans;
    for(int i=n-1; i>=0; i--){
        if(arr[i]>maxi){
            ans.push_back(arr[i]);
        }
        maxi = max(maxi, arr[i]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
    
}




