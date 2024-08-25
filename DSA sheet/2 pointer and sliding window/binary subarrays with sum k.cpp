class Solution {
private:
    int ans(vector<int>nums, int goal){
        int l=0, r=0, sum=0, cnt=0;
        while(r<nums.size()){
            sum+=nums[r];
            while(sum>goal && l<nums.size() && l<=r){
                sum = sum- nums[l];
                l++;
            }
            cnt = cnt + r-l+1;
            r++;
        }
        return cnt;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return ans(nums, goal)-ans(nums, goal-1);
    }
};

tc = 2* 2n
  sc = 1 
