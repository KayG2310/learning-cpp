class Solution {
public:
    void print(int ind, vector<int> &ds, int target, vector<vector<int>>&ans, vector<int>& candidates){
        if(ind == candidates.size()) {
            if(target == 0) {
                ans.push_back(ds);
            }
            return;
        }
        if(candidates[ind]<= target){
            // we can add
            ds.push_back(candidates[ind]);
            print(ind, ds, target-candidates[ind], ans, candidates);
            ds.pop_back();
        }
            print(ind+1, ds, target, ans, candidates);
        
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        int n = candidates.size();
        vector<int>ds;
        print(0, ds, target, ans, candidates);
        return ans;
    }
};
