// brute force -> O(n*k) sc = (n-k) to return the answer
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // brute force
        if(nums.size()==k) return {*max_element(nums.begin(), nums.end())};
        vector<int>ans;
        for(int i=0; i<=nums.size()-k; i++){
            int maxi = nums[i];
            for(int j = i+1; j<i+k; j++){
                maxi = max(maxi, nums[j]);
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;
        for(int i=0; i<nums.size(); i++){
            if(!dq.empty() && dq.front() == i-k) dq.pop_front();
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>= k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
/*
dry run : 1 3 -1 -3 5 3 6 7 k = 3
i = 0, if no while no, dq = 0, if no
i = 1, if no while yes, dq = 1, if no
i = 2, if no while no, dq = 1 2, if yes, ans = 3
i = 3, if 
*/
