// brute force ---> find all permutations and do a linear search use next_permutation(arr.begin(), arr.end())
// optimal ---> we use logic and prefixes
#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int>nums = {2,1,5,4,3,0,0};
    // we go from backwards and see where there's the dip
    int n = nums.size();
    int ind = -1;
    for(int i=n-2; i>=0; i--){
        if(nums[i]<nums[i+1]){
            ind = i;
            break
        }
    }
    if(ind == -1){
        reverse(nums.begin(), nums.end());
        return nums;
    }
    for(int i=n-1; i>=0;i--){
        if(nums[i]>nums[ind]){
            //righter is bigger than left one
            swap(nums[i], nums[ind]);
            break;
        }
    }
    reverse(nums.begin()+ind+1, nums.end());
}
/*
dry run- 
n = 7, ind = -1
i = 5 4 3 2 1 0
no if
i=4, no if
i=3, no if
i=2, no if
i=1, yes, ind = 1
break

for--> 6 5 4 3 2 1 0
i=6 no if
i=5, nope
i=4, yes, swap and reverse
*/
