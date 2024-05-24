#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &nums) {
    int len=nums.size();
    if(len==1){
        return nums;
    }
    else{
        sort(nums.begin(),nums.end());
        int sum = nums[0]+nums[1];
        nums.erase(nums.begin());
        nums.erase(nums.begin());
        nums.push_back(sum);
        return solve(nums);
    }
}

int main(){
    vector<int>v = {3,2,3,1,2,4,5,5,6};

    cout<<solve(v)[0];
    // 5 3 1 2 4 5 5 6
    // 8 1 2 4 5 5 6
    // 9 2 4 5 5 6
    // 11 4 5 5 6
    // 15 5 5 6
    // 41
}
