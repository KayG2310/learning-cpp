class Solution {
public:
    void foo(int index, int n, int k, vector<int>& ds, vector<vector<int>>& ans, vector<int>& arr) {
        if (index == arr.size()) {
            if (n == 0 && ds.size() == k) {
                ans.push_back(ds);
            }
            return;
        }
        if (arr[index] <= n) {
            ds.push_back(arr[index]);
            foo(index + 1, n - arr[index], k, ds, ans, arr);
            ds.pop_back();
        }
        foo(index + 1, n, k, ds, ans, arr);
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        foo(0, n, k, ds, ans, arr);
        return ans;
    }
};
