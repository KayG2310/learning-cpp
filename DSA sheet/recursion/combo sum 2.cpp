// brute force absolute , gives tle on 172/176
class Solution {
public:
    void print(int index, int target, vector<int>&ds, vector<int>&candidates, set<vector<int>>&ans1){
        if(index == candidates.size()){
            if(target == 0){
                ans1.insert(ds);
            }
            return;
        }
        if(candidates[index]<= target){
            ds.push_back(candidates[index]);
            print(index+1, target-candidates[index], ds, candidates, ans1);
            ds.pop_back();
        }
        print(index+1, target, ds, candidates, ans1);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if(accumulate(candidates.begin(), candidates.end(),0)==target) return {candidates};
        sort(candidates.begin(), candidates.end());
        set<vector<int>>ans1;
        vector<int>ds;
        vector<vector<int>>ans;
        print(0, target, ds, candidates, ans1);
        for(auto val: ans1){
            ans.push_back(val);
        }
        return ans;
    }
};
