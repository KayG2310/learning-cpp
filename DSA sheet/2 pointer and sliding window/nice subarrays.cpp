//https://leetcode.com/problems/count-number-of-nice-subarrays/submissions/1367502502/ 
//above is question link
class Solution {
private :
    int ans(vector<int>&nums, int k){
        int l=0, r=0, sum=0, cnt=0;
        while(r<nums.size()){
            sum += nums[r];
            while(sum>k && l<nums.size() && l<=r){
                sum -= nums[l];
                l++;
            }
            cnt += (r-l+1);
            r++;
        }
        return cnt;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0; i<nums.size(); i++){
            nums[i] = nums[i]%2;
        }
        return ans(nums, k)-ans(nums,k-1);
    }
};
