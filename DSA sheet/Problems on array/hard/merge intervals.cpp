// brute force solution --> nlogn(sorting) + 2n as we have continue and break, we are not iterating n times for one iteration

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        int n = nums.size();
        // this is the brute force technique
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            int start = nums[i][0];
            int end = nums[i][1];
            if( !ans.empty() && end<=ans.back()[1]){
                // means you are already lying inside 
                // the interval
                continue;
            }
            for(int j=i+1; j<n;j++){
                if(nums[j][0]<=end){
                    // meaning we can merge
                    end = max(end, nums[j][1]);
                }
                else break;
            }
            ans.push_back({start,end});
        }
        return ans;
    }
};
