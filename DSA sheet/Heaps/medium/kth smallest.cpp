class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &nums, int k) {
        // code here
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>>pq;
        for(int i=0; i<n; i++){
            pq.push(nums[i]);
        }
        k--;
        while(k--){
            pq.pop();
        }
        return pq.top();
    }
