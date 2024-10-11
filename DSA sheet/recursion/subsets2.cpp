// no duplicates, tc = 2^n * n + nlogn for sorting sc = 2^n 
class Solution {
public:
    void foo(int index, vector<int>&ds, vector<int>&nums, vector<vector<int>>&ans, int n){
        
            ans.push_back(ds);
        for(int i=index; i<n; i++){
            if(i!=index && nums[i]==nums[i-1]) continue;
            ds.push_back(nums[i]);
            foo(i+1, ds, nums, ans,n);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<int>ds;
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        foo(0,ds, nums, ans, n);
        return ans;
    }
};
