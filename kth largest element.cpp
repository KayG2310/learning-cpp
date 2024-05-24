#include<bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int> nums, int k) {
    /*
    sort(nums.begin(),nums.end(),[](int a,int b)->bool{return a>b;});
    return nums[k-1];
    */
       int n = nums.size();
    for(int i = 0; i<n; i++){
        nums[i] = (-1)*nums[i];
    }
    int count = 0;
    sort(nums.begin(), nums.end());
    auto it2 = nums.begin();
    for(auto it=nums.begin(); it!=nums.end(); it++){
        count+=1;
        if(count==k){
            return (-1)*(*it);
        }
        it2++;
        }
        return (-1)*(*it2);
    
}

int main(){
    vector<int>v = {3,2,3,1,2,4,5,5,6};
    int k = 4;
    cout<<findKthLargest(v, k);
}
