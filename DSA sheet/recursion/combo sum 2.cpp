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

// tc = 2^t*k
class Solution {
public:
    void print(int index, int target, vector<int>&ds, vector<int>&candidates, vector<vector<int>>&ans1){
        if(target == 0){
            ans1.push_back(ds);
            return;
        }
        for(int i=index; i<candidates.size(); i++){
            if(i>index && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            ds.push_back(candidates[i]);
            print(i+1, target-candidates[i], ds, candidates, ans1);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // if(accumulate(candidates.begin(), candidates.end(),0)==target) return {candidates};
        sort(candidates.begin(), candidates.end());
        // set<vector<int>>ans1;
        vector<int>ds;
        vector<vector<int>>ans;
        print(0, target, ds, candidates, ans);
        return ans;
    }
};
