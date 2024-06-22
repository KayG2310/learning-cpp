// brute force TLE on leetcode
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;
        int n = nums.size();
        for(int i=0; i<n-2 ; i++){
        // we should run it till n-3 imo
            for(int j = i+1; j<n-1; j++ ){
                for(int k = j+1; k<n; k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                        // to ensure there are no duplicates, we can sort these triplets
                        vector<int>temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};

// better solution is using math and hashmap - O(n2) still exceeds tle on 2 test cases
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> st;
        for(int i=0; i<n; i++){
            set<int> hashset;
            for(int j=i+1; j<n; j++){
                int third = -(nums[i]+nums[j]);
                if(hashset.find(third) != hashset.end()){
                    vector<int> temp = {nums[i], nums[j], third};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(nums[j]);
            }
        }
        vector<vector<int>>ans(st.begin(), st.end());
        return ans;
    }
};

// optimal solution
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            // if elements are same just skip the       iteration
            int j = i+1;
            int k = n-1;
            while(j<k){
                // no scope of equality
                int sum = nums[i] + nums[j] + nums[k];
                if(sum<0) j++;
                else if(sum>0) k--;
                else{
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j< k && nums[j]==nums[j-1]) j++;
                    while(j< k && nums[k]==nums[k+1]) k--;
                } 

            }

        }
        return ans;
    }
};
