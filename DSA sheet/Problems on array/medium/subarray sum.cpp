class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> m;
        m[0] = 1;
        int prefixsum = 0, count = 0;
        for(int i=0; i< nums.size(); i++){
            prefixsum+=nums[i];
            int rem = prefixsum - k;
            count += m[rem];
            m[prefixsum]++;
        }
        return count;
    }
};
