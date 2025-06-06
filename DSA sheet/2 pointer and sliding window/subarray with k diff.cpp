// better 2n, sc  n ---> this is optimal only
class Solution {
private:
    int ans(vector<int>& nums, int k){
        int cnt = 0, l=0, r=0;
        unordered_map<int,int>mpp;
        while(r<nums.size()){
            mpp[nums[r]]++;
            while(mpp.size()>k && l<nums.size()){
                mpp[nums[l]]--;
                if(mpp[nums[l]] == 0) mpp.erase(nums[l]);
                l++;
            }
                cnt += (r-l+1);
            r++;
        }
        return cnt;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return ans(nums,k)-ans(nums,k-1);
    }
};
