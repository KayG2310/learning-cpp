class Solution {
  public:
    void foo(int index, int sum, vector<int>&arr, int n, vector<int>&ans){
        if(index == n){
            // no condn just add it up
            ans.push_back(sum);
            return;
        }
        foo(index+1, sum+arr[index], arr, n, ans);
        foo(index+1, sum, arr, n, ans);
    }
    vector<int> subsetSums(vector<int> arr, int n) {
        vector<int>ans;
        foo(0, 0, arr, n, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
