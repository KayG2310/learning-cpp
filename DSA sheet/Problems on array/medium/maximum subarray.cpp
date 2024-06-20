// brute force - O(n^3)
#include<bits/stdc++.h>
using namespace std;

int main() {
    int arr[12] = {0,1,2,0,1,2,1,0,0,0,0,0};
    int n = sizeof(arr)/sizeof(int);
    int maxi=0;
    for(int i=0; i<n;i++){
        for(int j=i; j<n;j++){
            int sum=0;
            for(int k=i; k<=j;k++){
                sum+=arr[k];
            }
            maxi = max(maxi,sum);
        }
    }
    cout<<maxi;
}

// better approach - O(n^2)
#include<bits/stdc++.h>
using namespace std;

int main() {
    int arr[4] = {-5,1,2,-1};
    int n = sizeof(arr)/sizeof(int);
    int maxi=0;
    for(int i=0; i<n;i++){
        int sum=arr[i];
        for(int j=i+1; j<n;j++){
            sum+=arr[j];
            maxi = max(maxi,sum);
        }
    }
    cout<<maxi;
}
/*
// i=0
// j = 1 to 11
// j=1, sum = -4, maxi = 0
j=2, sum=-2, maxi = 0
j=3, sum=-3, maxi=0

i = 1
j=2 3
j=2, sum=3, maxi=3
j=3, sum=2, maxi = 3

i=2, j=3
sum=-1
*/


// optimal approach 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxi = INT_MIN;
        for(auto it: nums){
            sum+=it;
            maxi = max(sum,maxi);
            if(sum<0) sum=0;
          // we don't want negative sums
        }
        return maxi;
    }
};
